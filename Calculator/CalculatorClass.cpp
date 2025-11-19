#include "CalculatorClass.h"

CalculatorClass::CalculatorClass() {
	buttons[0] = Button(30, 320, 1);
	buttons[1] = Button(120, 320, 2);
	buttons[2] = Button(210, 320, 3);
	buttons[3] = Button(30, 410, 4);
	buttons[4] = Button(120, 410, 5);
	buttons[5] = Button(210, 410, 6);
	buttons[6] = Button(30, 500, 7);
	buttons[7] = Button(120, 500, 8);
	buttons[8] = Button(210, 500, 9);
	buttons[9] = Button(100, 260, 0);
	buttons[10] = Button(120, 260, -1);
	buttons[11] = Button(190, 260, -2);

	equation = "";
}

void CalculatorClass::drawButtons() {
	buttons[0].drawButton();
	buttons[1].drawButton();
	buttons[2].drawButton();
	buttons[3].drawButton();
	buttons[4].drawButton();
	buttons[5].drawButton();
	buttons[6].drawButton();
	buttons[7].drawButton();
	buttons[8].drawButton();
}

void CalculatorClass::showEquation() {
	DrawRectangle(30, 30, 340, 200, BLACK);
	DrawRectangleLines(30,30,340,200,GREEN);
	DrawText(equation.c_str(), 250, 190, 30, GREEN);
}