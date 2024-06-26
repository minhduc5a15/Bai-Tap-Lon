#include "rewards.h"

static const int rewards[16] = {0, 200, 400, 600, 1000, 2000, 3000, 6000, 10000, 14000, 22000, 30000, 40000, 60000, 85000, 150000};
static const int pos[16] = {0, 392, 365, 335, 308, 281, 254, 227, 200, 173, 146, 119, 93, 65, 41, 12};

static UnicodeText reward;
static V2 currMeasureText;

void setRewardBox() {
    int witdh = 477, height = 73;
    Image img = LoadImage(REWARD_BOX);
    V2 position = getCenter(rewardBoard.destRect, (V2){witdh, height});
    Rectangle destRect = {position.x, position.y, witdh, height};
    rewardBox = newContainer(img, img, destRect, (V2){});
}

void setRewardContainer(int level) {
    currReward = rewards[level - 1];
    char tmp[25];
    sprintf(tmp, "%d", currReward * 1000);
    char *value = addStr(tmp, " VND");
    reward = newUnicodeText(DEFAULT_FONT, value);
    Image img = LoadImage(REWARDS_BG);
    Rectangle destRect = {SCREEN_WIDTH - 250, SCREEN_HEIGHT / 2 - 300, 237, 431};
    rewardsContainer = newContainer(img, img, destRect, (V2) {});
    img = LoadImage(REWARD_BOARD);
    destRect = (Rectangle) {SCREEN_WIDTH / 2 - img.width / 2, SCREEN_HEIGHT / 2 - img.height / 2 - PADDING_LEFT, img.width, img.height};
    rewardBoard = newContainer(img, img, destRect, (V2) {});
    currMeasureText = MeasureTextEx(reward.font, value, 40, 0);
    img = LoadImage(LOGO);
    rewardLogo = newContainer(img, img, rewardBoard.destRect, (V2) {0, 0});
    setRewardBox();
}

void drawRewardContainer() {
    DrawContainer(rewardsContainer, 0, WHITE);
    DrawContainer(rewardBoard, 0, WHITE);
    DrawContainer(rewardLogo, 0, WHITE);
    DrawRectangle(SCREEN_WIDTH / 2 - rewardBoard.img.width / 2, SCREEN_HEIGHT / 2 - rewardBoard.img.height / 2 - PADDING_LEFT, rewardBoard.img.width, rewardBoard.img.height, setOpacity(BLACK, 0.75));
    DrawContainer(rewardBox, 0, WHITE);
    DrawUnicodeText(reward, getCenter(rewardBoard.destRect, currMeasureText), 40, 0, RAYWHITE);
    if (currLevel >= 1) DrawRectangle(SCREEN_WIDTH - 235, SCREEN_HEIGHT / 2 - 306 + pos[getCurrLevel()], 200, 28, setOpacity(YELLOW, 0.65));
}