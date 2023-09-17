#ifndef H_SCREEN
#define H_SCREEN

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "world.h"

static const char* CURSOR_HIDE = "\33[?25l";
static const char* CURSOR_SHOW = "\33[?25h";
static const char* CURSOR_RETURN = "\033[0;0H";

static const char* F_BLACK =        "\033[30m";
static const char* F_DARK_RED =     "\033[31m";
static const char* F_DARK_GREEN =   "\033[32m";
static const char* F_DARK_YELLOW =  "\033[33m";
static const char* F_DARK_BLUE =    "\033[34m";
static const char* F_DARK_MAGENTA = "\033[35m";
static const char* F_DARK_CYAN =    "\033[36m";
static const char* F_DARK_WHITE =   "\033[37m";

static const char* F_BRIGHT_BLACK =   "\033[90m";
static const char* F_BRIGHT_RED =     "\033[91m";
static const char* F_BRIGHT_GREEN =   "\033[92m";
static const char* F_BRIGHT_YELLOW =  "\033[93m";
static const char* F_BRIGHT_BLUE =    "\033[94m";
static const char* F_BRIGHT_MAGENTA = "\033[95m";
static const char* F_BRIGHT_CYAN =    "\033[96m";
static const char* F_WHITE =          "\033[97m";

static const char* F_DEFAULT = "\033[0m";

static const int BLOCK_HEIGHT = 2;
static const int BLOCK_WIDTH = 2;

typedef struct block {
    const char* color_code;
    uint8_t data;
} block_t;

typedef struct screen {
    int bheight, bwidth;
    block_t* color_buffer;
    float* depth_buffer;
} screen_t;

void block_init(block_t* block);
void block_free(block_t* block);
int block_set(block_t* block, int y, int x, int val);
void block_setcolor(block_t* block, const char* color);
int block_setall(block_t* block, uint8_t data, const char* color);
void block_print(block_t* block);

void scr_alloc(screen_t* screen, int height, int width);
void scr_free(screen_t* screen);
int scr_set(screen_t* screen, int y, int x, int val);
int scr_getblock(screen_t* screen, block_t** block, int y, int x);
int scr_setall(screen_t* screen, uint8_t* data, int len);
void scr_render(screen_t* screen, world_t* world);
void scr_clear(screen_t* screen);
void scr_print(screen_t* screen);

#endif
