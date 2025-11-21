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
	buttons[9] = Button(300, 590, 0);
	buttons[10] = Button(300, 500, '+');
	buttons[11] = Button(300, 410, '-');
	buttons[12] = Button(300, 320, '=');
	buttons[13] = Button(120, 590, '*');
	buttons[14] = Button(210, 590, '/');
	buttons[15] = Button(30, 590, 'C');
	buttons[16] = Button(120, 680, '.');
	buttons[17] = Button(30, 680, '(');
	buttons[18] = Button(210, 680, "complex\n mode");

	firstParenthesis = true;
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
	buttons[12].drawButton();
	buttons[13].drawButton();
	buttons[14].drawButton();
	buttons[15].drawButton();
	buttons[16].drawButton();
	buttons[17].drawButton();
	buttons[18].drawButton();
}

void CalculatorClass::showEquation() {
	DrawRectangle(30, 30, 340, 200, BLACK);
	DrawRectangleLines(30,30,340,200,GREEN);
	DrawText(equation.c_str(), 40, 190, 30, GREEN);
}

void CalculatorClass::handleButtonClicks() {
	// numbers
	if (buttons[0].isClicked() || IsKeyPressed(KEY_ONE)) {
		updateEquation(std::to_string(buttons[0].getSymbol()), false);
 	}if (buttons[1].isClicked() || IsKeyPressed(KEY_TWO)) {
		updateEquation(std::to_string(buttons[1].getSymbol()), false);
	}if (buttons[2].isClicked() || IsKeyPressed(KEY_THREE)) {
		updateEquation(std::to_string(buttons[2].getSymbol()), false);
	}if (buttons[3].isClicked() || IsKeyPressed(KEY_FOUR)) {
		updateEquation(std::to_string(buttons[3].getSymbol()), false);
	}if (buttons[4].isClicked() || IsKeyPressed(KEY_FIVE)) {
		updateEquation(std::to_string(buttons[4].getSymbol()), false);
	}if (buttons[5].isClicked() || IsKeyPressed(KEY_SIX)) {
		updateEquation(std::to_string(buttons[5].getSymbol()), false);
	}if (buttons[6].isClicked() || IsKeyPressed(KEY_SEVEN)) {
		updateEquation(std::to_string(buttons[6].getSymbol()), false);
	}if (buttons[7].isClicked() || IsKeyPressed(KEY_EIGHT)) {
		updateEquation(std::to_string(buttons[7].getSymbol()), false);
	}if (buttons[8].isClicked() || IsKeyPressed(KEY_NINE)) {
		updateEquation(std::to_string(buttons[8].getSymbol()),false);
	}if (buttons[9].isClicked() || IsKeyPressed(KEY_ZERO)) {
		updateEquation(std::to_string(buttons[9].getSymbol()), false);
	}

	// operators
	if (buttons[10].isClicked()) {
		updateEquation(std::string(1, static_cast<char>(buttons[10].getSymbol())), false);
		operations.push_back(static_cast<char>(buttons[10].getSymbol()));
	}if (buttons[11].isClicked()) {
		updateEquation(std::string(1, static_cast<char>(buttons[11].getSymbol())), false);
		operations.push_back(static_cast<char>(buttons[11].getSymbol()));
	}if (buttons[13].isClicked()) {
		updateEquation(std::string(1, static_cast<char>(buttons[13].getSymbol())), false);
		operations.push_back(static_cast<char>(buttons[13].getSymbol()));
	}if (buttons[14].isClicked()) {
		updateEquation(std::string(1, static_cast<char>(buttons[14].getSymbol())), false);
		operations.push_back(static_cast<char>(buttons[14].getSymbol()));
	}if (buttons[15].isClicked()) {
		updateEquation("",true);
		numbers.clear();
	}if (buttons[16].isClicked()) {
		updateEquation(std::string(1, static_cast<char>(buttons[16].getSymbol())), false);
		operations.push_back(static_cast<char>(buttons[16].getSymbol()));
	}if (buttons[17].isClicked()) {
		if (firstParenthesis) {
			updateEquation(std::string(1, static_cast<char>(buttons[17].getSymbol())), false);
			operations.push_back(static_cast<char>(buttons[17].getSymbol()));
			firstParenthesis = false;
		}
		else {
			updateEquation(")", false);
			operations.push_back(')');
			firstParenthesis = true;
		}
		
	}

	if (buttons[12].isClicked()) {
		
		getNumbers(equation);

		//number 1 + number 2

		if (numbers.size() >= 2) {
			double resultInt = 0;
			size_t opCount = std::min(numbers.size() > 0 ? numbers.size() - 1 : 0, operations.size());
			for (size_t i = 0; i < opCount; i++) {
				switch (operations[i])
				{
				case '+':
					resultInt = numbers[i] + numbers[i + 1];
					break;
				case '-':
					resultInt = numbers[i] - numbers[i + 1];
					break;
				case '*':
					resultInt = numbers[i] * numbers[i + 1];
					break;
				case '/':
					if (numbers[i + 1] != 0) {
						resultInt = numbers[i] / numbers[i + 1];
					}
					else {
						resultInt = 0; // Handle division by zero
					}
					break;
				default:
					break;
				}
			}
			updateEquation(std::to_string(resultInt), true);
			numbers.clear();

			getNumbers(equation);
		}
		
	}

	handleMiscKeys();
}

void CalculatorClass::updateEquation(const std::string& newEquation, bool equalsTriggerd) {
	if (equalsTriggerd)
		equation = newEquation;
	else
		equation += newEquation;
}

void CalculatorClass::getNumbers(const std::string & equation) {
	double number = 0;
	for (int i = 0; i <= equation.length();i++) {
		if (equation[i] >= '0' && equation[i] <= '9') {
			number = number * 10 + (equation[i] - '0');
		}
		else {
			numbers.push_back(number);
			number = 0;
		}
	}
}

void CalculatorClass::handleMiscKeys() {
	if (equation.length() > 0 && IsKeyPressed(KEY_BACKSPACE)) {
		if (numbers.empty()) {
			equation.pop_back();
		}
		else {
			int numberOfDigits = std::to_string(numbers.back()).length();
			while (numberOfDigits--) {
				equation.pop_back();
			}
			numbers.clear();
		}
	}
	if (IsKeyPressed(KEY_SPACE)) { updateEquation(" ", false); }
}