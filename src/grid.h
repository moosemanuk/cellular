#pragma once
#include <raylib.h>
#include <string>
#include "constants.h"
#include "colours.h"

class Grid
{
private:
    int grid[GRID_ROWS][GRID_COLS];

public:
    Grid();
    Grid(int initial);
    void Draw() const;
    void InitialiseGrid(int initial);
    void SetValue(int row, int col, int value);
    int GetValue(int row, int col) const;
    void ProcessRule();
    int CalculateState(int left, int middle, int right);
    int counter;
    bool drawing;
};