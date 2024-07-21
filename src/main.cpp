#include <raylib.h>
#include <iostream>
#include "grid.h"

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Simple Cellular Automaton");
    SetTargetFPS(TARGET_FPS);

    Grid grid;

    grid.SetValue(0, (int)GRID_COLS / 2, 1);

    while (!WindowShouldClose())
    {
        if (grid.drawing)
        {            
            grid.ProcessRule();         
        }
         if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
            DrawText("hello", SCREEN_HEIGHT/2, SCREEN_WIDTH/2, 20, BLACK);
        }
       
        BeginDrawing();        
        grid.Draw();
        ClearBackground(background);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}