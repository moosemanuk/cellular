#include <raylib.h>
#include <iostream>
#include "grid.h"

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Simple Cellular Automaton");
    SetTargetFPS(TARGET_FPS);

    Grid* grid = new Grid();

    if (START_WITH_RANDOM_SEED)
    {
        for (int i = 0; i < GRID_COLS - 1; i++)
        {
            int rand = GetRandomValue(0, 1);
            grid->SetValue(0, i, rand);
        }
    }
    else
    {
        grid->SetValue(0, GRID_COLS / 2, 1);
    }
    
    
    while (!WindowShouldClose())
    {
        if (grid->drawing)
        {            
            grid->ProcessRule();         
        }
        
        BeginDrawing();  
        ClearBackground(background);
        grid->Draw();
        
        EndDrawing();        
    }

    CloseWindow();
    return 0;
}