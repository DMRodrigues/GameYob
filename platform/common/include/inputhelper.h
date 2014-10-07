#pragma once
#include <stdio.h>
#include "io.h"

#define FAT_CACHE_SIZE 16

#define GB_A		    0x01
#define GB_B		    0x02
#define GB_SELECT		0x04
#define GB_START		0x08
#define GB_RIGHT		0x10
#define GB_LEFT		    0x20
#define GB_UP			0x40
#define GB_DOWN		    0x80


/*
#define MOTION_SENSOR_MAX 2197
#define MOTION_SENSOR_MIN 1897
*/
#define MOTION_SENSOR_RANGE 256
#define MOTION_SENSOR_MID 0


// Function keys
enum {
    FUNC_KEY_NONE,
    FUNC_KEY_A, FUNC_KEY_B, FUNC_KEY_LEFT, FUNC_KEY_RIGHT, FUNC_KEY_UP, FUNC_KEY_DOWN, FUNC_KEY_START, FUNC_KEY_SELECT,
    FUNC_KEY_MENU, FUNC_KEY_MENU_PAUSE, FUNC_KEY_SAVE, FUNC_KEY_AUTO_A, FUNC_KEY_AUTO_B, FUNC_KEY_FAST_FORWARD, FUNC_KEY_FAST_FORWARD_TOGGLE,
    FUNC_KEY_SCALE, FUNC_KEY_RESET,

    NUM_FUNC_KEYS,
};

// Menu keys
enum {
    MENU_KEY_A, MENU_KEY_B, MENU_KEY_UP, MENU_KEY_DOWN, MENU_KEY_LEFT, MENU_KEY_RIGHT,
    MENU_KEY_L, MENU_KEY_R, MENU_KEY_X, MENU_KEY_Y,

    NUM_MENU_KEYS,
};


extern bool fastForwardMode; // controlled by the toggle hotkey
extern bool fastForwardKey;  // only while its hotkey is pressed
extern u8 buttonsPressed;

extern char borderPath[MAX_FILENAME_LEN];
extern bool biosExists;
extern int rumbleInserted;


void initInput();
void flushFatCache();

void startKeyConfigChooser();
bool readConfigFile();
void writeConfigFile();

bool keyPressed(int key);
bool keyPressedAutoRepeat(int key);
bool keyJustPressed(int key);
// Consider this key unpressed until released and pressed again
void forceReleaseKey(int key);

int mapFuncKey(int gbKey); // Maps a functional key to a physical key.
int mapMenuKey(int menuKey);

void inputUpdateVBlank();

void system_doRumble(bool rumbleVal);
int system_getMotionSensorX();
int system_getMotionSensorY();

void system_checkPolls();
void system_waitForVBlank();