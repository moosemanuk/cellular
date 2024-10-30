#pragma once
#include <cstdint>

const int SCREEN_WIDTH = 1500;
const int SCREEN_HEIGHT = 750;


const int TARGET_FPS = 60;

// I want this to be 2
const int CELL_SIZE = 2;
const int GRID_ROWS = (int)(SCREEN_HEIGHT / CELL_SIZE);
const int GRID_COLS = (int)(SCREEN_WIDTH / CELL_SIZE);

const int GRID_FEATHER = 1;

const uint8_t RULE = 70;