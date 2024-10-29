#pragma once
#include <raylib.h>
#include <string>
#include "constants.h"
#include "colours.h"

class Grid
{
private:
    uint8_t grid[GRID_ROWS][GRID_COLS];

public:
    Grid();
    Grid(int initial);
    void Draw() const;
    void InitialiseGrid(int initial);
    void SetValue(int row, int col, int value);
    uint8_t GetValue(int row, int col) const;
    void ProcessRule();
    uint8_t CalculateState(uint8_t left, uint8_t middle, uint8_t right);
    int counter;
    bool drawing;
};