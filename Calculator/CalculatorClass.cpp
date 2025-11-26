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
	buttons[16] = Button(120, 680, ')');
	buttons[17] = Button(30, 680, '(');
	buttons[18] = Button(300, 680, "complex mode", 80, 80);
	buttons[19] = Button(30, 500, "sin", 80, 80);
	buttons[20] = Button(210,680,'.');




	firstParenthesis = true;
	complexMode = false;
}

void CalculatorClass::drawButtons() {
	if (complexMode) {
		buttons[19].drawButton();
	}
	else {
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
		buttons[20].drawButton();
	}
	
		
	
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
		if (!parenthesies.empty()) {
			if (parenthesies.front() == '(' && parenthesies.back() != ')') {
				parenthesies.push_back('+');
			}
		}
		
		updateEquation(std::string(1, static_cast<char>(buttons[10].getSymbol())), false);
		operations.push_back(static_cast<char>(buttons[10].getSymbol()));
		
	}if (buttons[11].isClicked()) {
		if (!parenthesies.empty()) {
			if (parenthesies.front() == '(' && parenthesies.back() != ')') {
				parenthesies.push_back('+');
			}
		}

		updateEquation(std::string(1, static_cast<char>(buttons[11].getSymbol())), false);
		operations.push_back(static_cast<char>(buttons[11].getSymbol()));
	}if (buttons[13].isClicked()) {
		if (!parenthesies.empty()) {
			if (parenthesies.front() == '(' && parenthesies.back() != ')') {
				parenthesies.push_back('+');
			}
		}
		updateEquation(std::string(1, static_cast<char>(buttons[13].getSymbol())), false);
		operations.push_back(static_cast<char>(buttons[13].getSymbol()));
	}if (buttons[14].isClicked()) {
		if (!parenthesies.empty()) {
			if (parenthesies.front() == '(' && parenthesies.back() != ')') {
				parenthesies.push_back('+');
			}
		}
		updateEquation(std::string(1, static_cast<char>(buttons[14].getSymbol())), false);
		operations.push_back(static_cast<char>(buttons[14].getSymbol()));
	}if (buttons[15].isClicked()) {
		updateEquation("",true);
		numbers.clear();
	}if (buttons[16].isClicked()) {
		updateEquation(")", false);
		parenthesiesIndexes.push_back(getIndexFromEquation(')'));
		parenthesies.push_back(')');

	}if (buttons[17].isClicked()) {
			updateEquation("(", false);
			parenthesiesIndexes.push_front(getIndexFromEquation('('));
			parenthesies.push_front('(');

	}if (buttons[20].isClicked()) {
		updateEquation(".", false);
	}

	if (buttons[12].isClicked()) {
		getNumbers(equation);

		if (numbers.size() >= 2) {
			double resultDouble = 0;
			size_t opCount = std::min(numbers.size() > 0 ? numbers.size() - 1 : 0, operations.size());
			for (size_t i = 0; i < opCount; i++) {
				if (!parenthesiesMathing()) {
					resultDouble = mathing();
				}
			}

			std::string resultStr = std::to_string(resultDouble);
			resultStr.erase(resultStr.find('.') + 3, std::string::npos); // Remove trailing zeros
			updateEquation(resultStr, true);

			numbers.clear();
			operations.clear();
			parenthesiesIndexes.clear();

			getNumbers(equation);
		}
		
	}

	if (buttons[18].isClicked()) {
		complexMode = !complexMode;

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
	bool change = false;
	double number = 0;
	for (int i = 0; i <= equation.length();i++) {
		if (equation[i] >= '0' && equation[i] <= '9') {
			number = number * 10 + (equation[i] - '0');
			change = true;
		}
		else if (equation[i] == '.') {
			continue;
		}
		else if (change) {
			numbers.push_back(number);
			number = 0;
			change = false;
		}
	}
}

int CalculatorClass::getIndexFromEquation(const char& target) {
	for (int i = 0;i < equation.length();i++)
		if (equation[i] == target) return i;
}

void CalculatorClass::handleMiscKeys() {
	if (equation.length() > 0 && IsKeyPressed(KEY_BACKSPACE)) {
		if (numbers.size() == 1) {
			updateEquation("", true);

			// delete from the parethesies arr too
			if (equation.back() == '(') 
				parenthesiesIndexes.pop_front();
			else if(equation.back() == ')') 
				parenthesiesIndexes.pop_back();
			
		}
		else {
			equation.pop_back();
		}
	}
	if (IsKeyPressed(KEY_SPACE)) { updateEquation(" ", false); }
}

double CalculatorClass::mathing() {
	double resultDouble = 0;
	size_t opCount = std::min(numbers.size() > 0 ? numbers.size() - 1 : 0, operations.size());
	for (size_t i = 0; i < opCount; i++) {
		switch (operations[i])
		{
		case '+':
			resultDouble = numbers[i] + numbers[i + 1];
			break;
		case '-':
			resultDouble = numbers[i] - numbers[i + 1];
			break;
		case '*':
			resultDouble = numbers[i] * numbers[i + 1];
			break;
		case '/':
			if (numbers[i + 1] != 0) {
				resultDouble = numbers[i] / numbers[i + 1];
			}
			else {
				resultDouble = 0; // Handle division by zero
			}
			break;
		default:
			break;

			operations.pop_front();
		}					
	}

	return resultDouble;
}

bool CalculatorClass::parenthesiesMathing() {
	double resultDouble = 0;
	size_t opCount = std::min(numbers.size() > 0 ? numbers.size() - 1 : 0, operations.size());
	for (size_t i = 0; i < opCount; i++) {
		if (parenthesiesIndexes.size() % 2 == 0 && parenthesiesIndexes.size()) {
			for (int start = 0;start < parenthesiesIndexes.size() - 1;start++) {
				int num1 = numbers[parenthesiesIndexes[start] - 1];
				int num2 = numbers[parenthesiesIndexes.back() / parenthesies.size() / 2];

				switch (parenthesies[start + 1]){
				case '+':
					resultDouble = num1 + num2;
					break;
				case '-':
					resultDouble = numbers[parenthesiesIndexes[start] - 1] - numbers[parenthesiesIndexes.back() - 1];
					break;
				case '*':
					resultDouble = numbers[parenthesiesIndexes[start] - 1] * numbers[parenthesiesIndexes.back() - 1];
					break;
				case '/':
					if (numbers[parenthesiesIndexes.back() - 1] != 0) {
						resultDouble = numbers[parenthesiesIndexes[start] - 1] / numbers[parenthesiesIndexes.back() - 1];
					}
					else {
						resultDouble = 0; // Handle division by zero
					}
					break;
				default:
					break;

					operations.pop_front();
				}
				numbers.push_back(resultDouble);
				parenthesiesIndexes.clear();
			}
		}
		else {
			return false;
		}
	}
}