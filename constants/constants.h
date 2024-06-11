#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
#include <raylib.h>
#define mousePos GetMousePosition()
typedef void (*Callback)();
typedef Vector2 V2;
typedef Vector3 V3;
typedef Vector4 V4;
typedef Texture2D T2;
extern const int SCREEN_WIDTH; /* px */
extern const int SCREEN_HEIGHT; /* px */
extern const int FPS; /* Frames per second */
extern const int INPUT_PADDING_LEFT; /*px */
extern const char *BACKGROUND_IMAGE_DIR; /* Background image directory */
extern const char *START_BUTTON_DIR;
extern const char *TITLE_WINDOW_LOGIN;
extern const char *TITLE_WINDOW_GAME;
extern const Color transparent;
#endif