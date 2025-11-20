#include "CalculatorClass.h"

CalculatorClass::CalculatorClass() {
	buttons[0] = Button(30, 500, 1);
	buttons[1] = Button(120, 500, 2);
	buttons[2] = Button(210, 500, 3);
	buttons[3] = Button(30, 410, 4);
	buttons[4] = Button(120, 410, 5);
	buttons[5] = Button(210, 410, 6);
	buttons[6] = Button(30, 320, 7);
	buttons[7] = Button(120, 320, 8);
	buttons[8] = Button(210, 320, 9);
	buttons[9] = Button(300, 500, '+');
	buttons[10] = Button(300, 410, '-');
	buttons[11] = Button(300, 320, '=');

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
	buttons[9].drawButton();
	buttons[10].drawButton();
	buttons[11].drawButton();
}

void CalculatorClass::showEquation() {
	DrawRectangle(30, 30, 340, 200, BLACK);
	DrawRectangleLines(30,30,340,200,GREEN);
	DrawText(equation.c_str(), 40, 190, 30, GREEN);
}

void CalculatorClass::handleButtonClicks() {
	if (buttons[0].isClicked()) {
		updateEquation(std::to_string(buttons[0].getSymbol()), false);
		numbers.push_back(buttons[0].getSymbol());
	}if (buttons[1].isClicked()) {
		updateEquation(std::to_string(buttons[1].getSymbol()), false);
		numbers.push_back(buttons[1].getSymbol());
	}if (buttons[2].isClicked()) {
		updateEquation(std::to_string(buttons[2].getSymbol()), false);
		numbers.push_back(buttons[2].getSymbol());
	}if (buttons[3].isClicked()) {
		updateEquation(std::to_string(buttons[3].getSymbol()), false);
		numbers.push_back(buttons[3].getSymbol());
	}if (buttons[4].isClicked()) {
		updateEquation(std::to_string(buttons[4].getSymbol()), false);
		numbers.push_back(buttons[4].getSymbol());
	}if (buttons[5].isClicked()) {
		updateEquation(std::to_string(buttons[5].getSymbol()), false);
		numbers.push_back(buttons[5].getSymbol());
	}if (buttons[6].isClicked()) {
		updateEquation(std::to_string(buttons[6].getSymbol()), false);
		numbers.push_back(buttons[6].getSymbol());
	}if (buttons[7].isClicked()) {
		updateEquation(std::to_string(buttons[7].getSymbol()), false);
		numbers.push_back(buttons[7].getSymbol());
	}if (buttons[8].isClicked()) {
		updateEquation(std::to_string(buttons[8].getSymbol()),false);
		numbers.push_back(buttons[8].getSymbol());
	}
	if (buttons[9].isClicked()) {
		updateEquation(std::string(1, static_cast<char>(buttons[9].getSymbol())), false);
		operations.push_back(static_cast<char>(buttons[9].getSymbol()));
	}
	if (buttons[10].isClicked()) {
		updateEquation(std::string(1, static_cast<char>(buttons[10].getSymbol())), false);
		operations.push_back(static_cast<char>(buttons[10].getSymbol()));
	}
	if (buttons[11].isClicked()) {
		//number 1 + number 2
		int resultInt = 0;
		for (int i = 0;i < numbers.size() - 1 || i < operations.size()  ;i++) {
			switch (operations[i])
			{
				case '+':
					resultInt = numbers[i] + numbers[i + 1];
					break;
				case '-':
					resultInt = numbers[i] - numbers[i + 1];
					break;

			default:
				break;
			}
		}
		updateEquation(std::to_string(resultInt),true);
	}
	if (IsKeyPressed(KEY_BACKSPACE)) {
		if (equation.size() > 1) {
			equation.pop_back();
			equation.pop_back();
		}
		
	}
}