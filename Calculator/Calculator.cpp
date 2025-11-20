#include <iostream>
#include "raylib.h"

#include "CalculatorClass.h"

int main()
{
    InitWindow(400, 800, "Essential Raylib");
    SetTargetFPS(60);
	CalculatorClass calculator;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(DARKGRAY);

		calculator.drawButtons();
		calculator.handleButtonClicks();
		calculator.showEquation();
        
        EndDrawing();
    }

    CloseWindow();
    return 0;

}


