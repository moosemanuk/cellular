#include "grid.h"
#include <iostream>
#include <bitset>

Grid::Grid()
{
    InitialiseGrid(0);
    // //debug
    // for(int i = 0 ; i < GRID_ROWS ; i++){
    //     for(int j = 0 ; j < GRID_COLS ; j ++){
    //         std::cout << grid[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    //  Checking this - the grid initialises correctly with all zeros

    counter = 0;
    drawing = true;
}

Grid::Grid(int initial)
{
    InitialiseGrid(initial);
    counter = 0;
    drawing = true;
}

void Grid::InitialiseGrid(int initial)
{
    for (int row = 0; row < GRID_ROWS; row++)
    {
        for (int col = 0; col < GRID_COLS; col++)
        {
            grid[row][col] = initial;
        }
    }
}

void Grid::Draw()
{
    for (int row = 0; row < GRID_ROWS; row++)
    {
        for (int col = 0; col < GRID_COLS; col++)
        {
            Color cellcolour = inactivecell;
            if (grid[row][col] == 1)
            {
                // cellcolour = activecell;
                cellcolour = sparecolour;
            }
            DrawRectangle(col * CELL_SIZE + 1, row * CELL_SIZE + 1, CELL_SIZE - GRID_FEATHER, CELL_SIZE - GRID_FEATHER, cellcolour);
        }
    }
}

void Grid::SetValue(int row, int col, int value)
{
    this->grid[row][col] = value;
}

int Grid::GetValue(int row, int col)
{
    return grid[row][col];
}

void Grid::ProcessRule()
{
    int currentrow = counter;
    if (counter < GRID_ROWS)
    {
        if (currentrow < GRID_ROWS - 1)
        {
            grid[currentrow + 1][0] = grid[currentrow][0];
            grid[currentrow + 1][GRID_COLS - 1] = grid[currentrow][GRID_COLS - 1];

            for (int col = 0; col < GRID_COLS - 1; col++)
            {
                int left, middle, right;
                if (col == 0)
                {
                    left = grid[counter][GRID_COLS] - 1;
                }
                else
                {
                    left = grid[counter][col - 1];
                }

                middle = grid[counter][col];
                
                if (col == GRID_COLS - 1)
                {
                    right = grid[counter][0];
                }
                else
                {
                    right = grid[counter][col + 1];
                }
                grid[currentrow + 1][col] = CalculateState(left, middle, right);
            }
            counter++;
        }
        else
        {
            drawing = false;
        }
    }
}

int Grid::CalculateState(int left, int middle, int right)
{
    std::string ruleset = std::bitset<8>(RULE).to_string();
    if (left == 0 && middle == 0 && right == 0)
    {
        // get first char from string, convert to integer, return
        char ch = ruleset[7];
        return ch - '0';
    }
    else if (left == 0 && middle == 0 && right == 1)
    {
        char ch = ruleset[6];
        return ch - '0';
    }
    else if (left == 0 && middle == 1 && right == 0)
    {
        char ch = ruleset[5];
        return ch - '0';
    }
    else if (left == 0 && middle == 1 && right == 1)
    {
        char ch = ruleset[4];
        return ch - '0';
    }
    else if (left == 1 && middle == 0 && right == 0)
    {
        char ch = ruleset[3];
        return ch - '0';
    }
    else if (left == 1 && middle == 0 && right == 1)
    {
        char ch = ruleset[2];
        return ch - '0';
    }
    else if (left == 1 && middle == 1 && right == 0)
    {
        char ch = ruleset[1];
        return ch - '0';
    }
    else if (left == 1 && middle == 1 && right == 1)
    {
        char ch = ruleset[0];
        return ch - '0';
    }
    else
    {
        return 0;
    }
}
