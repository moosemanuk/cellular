#include <raylib.h>
#include <iostream>
#include "grid.h"

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Simple Cellular Automaton");
    SetTargetFPS(TARGET_FPS);

    Grid* grid = new Grid();

    grid->SetValue(0, (int)GRID_COLS / 2, 1);

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