#include "answers.h"

static V2 pos[4];

static int fontSize = 32;

static AnsContainer *containers[4] = {&ansContainerA, &ansContainerB, &ansContainerC, &ansContainerD};

static void setAnswer(AnsContainer *container, Question question, Image img, Image imgSelected, Rectangle rect) {
    char letter = container->answer.answer[0];
    container->answer = question.answers[letter - 'A'];
    container->answer.isCorrect = (letter == question.correctAnswer[0]);
    container->container = newContainer(img, imgSelected, rect, (V2) {});
    container->answer.value = newUnicodeText(DEFAULT_FONT, addStr(addStr(container->answer.answer, ": "), container->answer.value.text));
}

static Question curr;

void setAnswers(int level) {
    Image imgs[4] = {LoadImage(A_ANSWER), LoadImage(B_ANSWER), LoadImage(C_ANSWER_DIR), LoadImage(D_ANSWER_DIR)};
    Image imgsSelected[4] = {LoadImage(A_ANSWER_SELECTED), LoadImage(B_ANSWER_SELECTED), LoadImage(C_ANSWER_SELECTED), LoadImage(D_ANSWER_SELECTED)};
    char *answers[4] = {"A", "B", "C", "D"};
    curr = questionDb[level];
    Rectangle rects[4] = {{0, 588, 640, 57}, {SCREEN_WIDTH - imgs[1].width, 588, 640, 57}, {0, 645, 640, 57}, {SCREEN_WIDTH - imgs[3].width, 645, 640, 57}};
    for (int i = 0; i < 4; ++i) {
        containers[i]->answer.answer = answers[i];
        setAnswer(containers[i], curr, imgs[i], imgsSelected[i], rects[i]);
        pos[i] = getRight(containers[i]->container.destRect, MeasureTextEx(containers[i]->answer.value.font, containers[i]->answer.value.text, fontSize, SPACING), PADDING_LEFT, i % 2 == 0 ? 246 : 0);
    }
}

void showCorrectAnswer() {
    char correctAns = currQuest.correctAnswer[0];
    char *dir;
    switch (correctAns) {
        case 'A':
            dir = strdup(A_RIGHT_ANSWER);
            break;
        case 'B':
            dir = strdup(B_RIGHT_ANSWER);
            break;
        case 'C':
            dir = strdup(C_RIGHT_ANSWER);
            break;
        case 'D':
            dir = strdup(D_RIGHT_ANSWER);
            break;
        default:
            break;
    }
    auto img = LoadImage(dir);
    if (correctAns == 'A') {
        ansContainerA.container = newContainer(img, img, ansContainerA.container.destRect, (V2) {});
    }
    else if (correctAns == 'B') {
        ansContainerB.container = newContainer(img, img, ansContainerB.container.destRect, (V2) {});
    }
    else if (correctAns == 'C') {
        ansContainerC.container = newContainer(img, img, ansContainerC.container.destRect, (V2) {});
    }
    else if (correctAns == 'D') {
        ansContainerD.container = newContainer(img, img, ansContainerD.container.destRect, (V2) {});
    }
}

static bool isShowCorrectAns = false;

void drawAnswers() {
    if (!getIsSleeping()) {
        for (int i = 0; i < 4; ++i) {
            DrawContainer(containers[i]->container, 0, WHITE);
            DrawUnicodeText(containers[i]->answer.value, pos[i], fontSize, SPACING, WHITE);
        }
    }
    else {
        if (!isShowCorrectAns) {
            showCorrectAnswer();
            isShowCorrectAns = true;
        }
        for (int i = 0; i < 4; ++i) {
            DrawContainer(containers[i]->container, 0, WHITE);
            DrawUnicodeText(containers[i]->answer.value, pos[i], fontSize, SPACING, WHITE);
        }
    }
}