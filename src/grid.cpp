#include "grid.h"
#include <iostream>

Grid::Grid()
{
    InitialiseGrid(0);
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

void Grid::Draw() const
{
    for (int row = 0; row < GRID_ROWS; row++)
    {
        for (int col = 0; col < GRID_COLS; col++)
        {
            Color cellcolour = inactivecell;
            if (grid[row][col] == 1)
            {
                cellcolour = activecell;
                //cellcolour = sparecolour;
            }
            DrawRectangle(col * CELL_SIZE + 1, 
                          row * CELL_SIZE + 1, 
                          CELL_SIZE - GRID_FEATHER, 
                          CELL_SIZE - GRID_FEATHER, 
                          cellcolour);
        }
    }
}

void Grid::SetValue(int row, int col, int value)
{
    this->grid[row][col] = value;
}

uint8_t Grid::GetValue(int row, int col) const
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

            for (int col = 0; col < GRID_COLS; col++)
            {
                uint8_t left, middle, right;
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

uint8_t Grid::CalculateState(uint8_t left, uint8_t middle, uint8_t right)
{    
    int chunk = left << 2 | middle << 1 | right;
    switch(chunk)
    {
        case 0: return RULE & 0b00000001; break;
        case 1: return (RULE >> 1) & 0b00000001; break;
        case 2: return (RULE >> 2) & 0b00000001; break;
        case 3: return (RULE >> 3) & 0b00000001; break;
        case 4: return (RULE >> 4) & 0b00000001; break;
        case 5: return (RULE >> 5) & 0b00000001; break;
        case 6: return (RULE >> 6) & 0b00000001; break;
        case 7: return (RULE >> 7) & 0b00000001; break;
        default:
            return 0;
            break;
    }
}
