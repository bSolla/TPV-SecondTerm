#pragma once
#include "sdl_includes.h"

// ---------------------------------------- reduce speed
const double REDUCE_SPEED_FACTOR = 0.995;

// ---------------------------------------- thrust 
static SDL_Keycode THRUST_KEY = SDLK_UP;
const double THRUST_VALUE = 0.5;
const double SPEED_LIMIT = 2.0;

// ---------------------------------------- rotation
static SDL_Keycode ROTATE_CLOCKWISE = SDLK_RIGHT;
static SDL_Keycode ROTATE_COUNTERCLOCKWISE = SDLK_LEFT;
const double ALPHA = 5.0;

// ---------------------------------------- gun
static SDL_Keycode GUN_KEY = SDLK_SPACE;