#include "CalculatorClass.h"

CalculatorClass::CalculatorClass() {
	buttons[0] = Button(30.0f, 500.0f, 1);
	buttons[1] = Button(120.0f, 500.0f, 2);
	buttons[2] = Button(210.0f, 500.0f, 3);
	buttons[3] = Button(30.0f, 410.0f, 4);
	buttons[4] = Button(120.0f, 410.0f, 5);
	buttons[5] = Button(210.0f, 410.0f, 6);
	buttons[6] = Button(30.0f, 320.0f, 7);
	buttons[7] = Button(120.0f, 320.0f, 8);
	buttons[8] = Button(210.0f, 320.0f, 9);
	buttons[9] = Button(300.0f, 590.0f, 0);
	buttons[10] = Button(300.0f, 500.0f, '+');
	buttons[11] = Button(300.0f, 410.0f, '-');
	buttons[12] = Button(300.0f, 320.0f, '=');
	buttons[13] = Button(120.0f, 590.0f, '*');
	buttons[14] = Button(210.0f, 590.0f, '/');
	buttons[15] = Button(30.0f, 590.0f, 'C');
	buttons[16] = Button(120.0f, 680.0f, ')');
	buttons[17] = Button(30.0f, 680.0f, '(');
	buttons[18] = Button(300.0f, 680.0f, "complex \n  mode", 80.0f, 80.0f);
	buttons[19] = Button(30.0f, 500.0f, "sin", 80.0f, 80.0f);
	buttons[20] = Button(210.0f, 680.0f, '.');

	buttons[21] = Button(120.0f, 500.0f, "cos", 80.0f, 80.0f);
	buttons[22] = Button(210.0f, 500.0f, "tan", 80.0f, 80.0f);
	buttons[23] = Button(30.0f, 320.0f, "log", 80.0f, 80.0f);
	buttons[24] = Button(300.0f, 500.0f, "rad", 80.0f, 80.0f);
	buttons[25] = Button(120.0f, 410.0f, 'e');
	buttons[26] = Button(210.0f, 410.0f, "pi", 80.0f, 80.0f);
	buttons[27] = Button(300.0f, 410.0f, "x^2", 80.0f, 80.0f);
	buttons[28] = Button(300.0f, 320.0f, "root", 80.0f, 80.0f);
	buttons[29] = Button(120.0f, 320.0f, "e^2", 80.0f, 80.0f);



	complexMode = false;
}

void CalculatorClass::drawButtons() {
	if (complexMode) {
		buttons[15].drawButton();
		buttons[18].drawButton();
		buttons[19].drawButton();
		buttons[21].drawButton();
		buttons[22].drawButton();
		buttons[23].drawButton();
		buttons[24].drawButton();
		buttons[25].drawButton();
		buttons[26].drawButton();
		buttons[27].drawButton();
		buttons[28].drawButton();
		buttons[29].drawButton();
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
	if (!complexMode) {
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
			updateEquation(std::to_string(buttons[8].getSymbol()), false);
		}if (buttons[9].isClicked() || IsKeyPressed(KEY_ZERO)) {
			updateEquation(std::to_string(buttons[9].getSymbol()), false);
		}

		// operators
		if (buttons[10].isClicked()) {
			if (!parenthesies.empty()) {
				if (parenthesies.front() == '(' && parenthesies.back() != ')') {
					if (parenthesies.size() == 1) {
						parenthesies.push_back('+');
					}
					else {
						parenthesies.push_back('+');

					}
				}
			}

			updateEquation(std::string(1, static_cast<char>(buttons[10].getSymbol())), false);
			operations.push_back(static_cast<char>(buttons[10].getSymbol()));

		}if (buttons[11].isClicked()) {
			if (!parenthesies.empty()) {
				if (parenthesies.front() == '(' && parenthesies.back() != ')') {
					if (parenthesies.size() == 1) {
						parenthesies.push_back('-');
					}
					else {
						parenthesies.push_back('-');

					}
				}
			}

			updateEquation(std::string(1, static_cast<char>(buttons[11].getSymbol())), false);
			operations.push_back(static_cast<char>(buttons[11].getSymbol()));
		}if (buttons[13].isClicked()) {
			if (!parenthesies.empty()) {
				if (parenthesies.front() == '(' && parenthesies.back() != ')') {
					if (parenthesies.size() == 1) {
						parenthesies.push_back('*');
					}
					else {
						parenthesies.push_back('*');

					}
				}
			}
			updateEquation(std::string(1, static_cast<char>(buttons[13].getSymbol())), false);
			operations.push_back(static_cast<char>(buttons[13].getSymbol()));
		}if (buttons[14].isClicked()) {
			if (!parenthesies.empty()) {
				if (parenthesies.front() == '(' && parenthesies.back() != ')') {
					if (parenthesies.size() == 1) {
						parenthesies.push_back('/');
					}
					else {
						parenthesies.push_back('/');

					}
				}
			}
			updateEquation(std::string(1, static_cast<char>(buttons[14].getSymbol())), false);
			operations.push_back(static_cast<char>(buttons[14].getSymbol()));
		}
	}
	else {
		if (buttons[18].isClicked()) {

		}
		if (buttons[19].isClicked()) {

		}
		if (buttons[21].isClicked()) {

		}
		if (buttons[22].isClicked()) {

		}
		if (buttons[23].isClicked()) {

		}
		if (buttons[24].isClicked()) {

		}
		if (buttons[25].isClicked()) {
			updateEquation(std::to_string(buttons[25].getSymbol()), false);
		}
		if (buttons[26].isClicked()) {
			updateEquation(std::to_string(buttons[26].getSymbol()), false);

		}
		if (buttons[27].isClicked()) {

		}
		if (buttons[28].isClicked()) {

		}
		if (buttons[29].isClicked()) {

		}
	}
	// clear
	if (buttons[15].isClicked()) {
		updateEquation("",true);
		numbers.clear();
	}
	// closing braket
	if (buttons[16].isClicked()) {
		updateEquation(")", false);
		parenthesiesIndexes.push_back(getLatestIndexFromEquation(')'));
		parenthesies.push_back(')');

	}
	// opening braket
	if (buttons[17].isClicked()) {
			if (parenthesiesIndexes.empty()) {
				parenthesiesIndexes.push_back(getSpacesSinceLast(0));
			}
			else {
				int previousOpeningParethesiesIndex = getLatestIndexFromEquation('(');
				
				std::deque<int>::iterator previousOpeningParethesies = 
					std::find(parenthesiesIndexes.begin(), parenthesiesIndexes.end(),previousOpeningParethesiesIndex);

				parenthesiesIndexes.insert(previousOpeningParethesies + 1, previousOpeningParethesiesIndex + getSpacesSinceLast(previousOpeningParethesiesIndex));
			}
			parenthesies.push_front('(');
			updateEquation("(", false);

	}
	// decimal point
	if (buttons[20].isClicked()) {
		updateEquation(".", false);
	}

	// equals
	if (buttons[12].isClicked()) {
		getNumbers(equation);

		if (numbers.size() >= 2) {
			double resultDouble = 0;
			int operationsSize = operations.size();
			for (size_t i = 0; i < operationsSize; i++) {
				if (parenthesiesMathing() == false) {
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

	// enter complex mode
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
	double number = 0;
	bool isDecimal = false;
	double decimalPlace = 0.1;

	for (char c : equation) {
		if (isdigit(c)) {
			if (isDecimal) {
				number += (c - '0') * decimalPlace;
				decimalPlace *= 0.1;
			}
			else {
				number = number * 10 + (c - '0');
			}
		}
		else if (c == '.') {
			isDecimal = true;
		}
		else {
			// Non-digit and non-decimal point: push number if any
			if (isDecimal || number != 0) {
				numbers.push_back(number);
				number = 0;
				isDecimal = false;
				decimalPlace = 0.1;
			}
		}
	}
	// Push the last number if the string ends with a number
	if (isDecimal || number != 0) {
		numbers.push_back(number);
	}

}

int CalculatorClass::getLatestIndexFromEquation(const char& target) {
	std::deque<int> indexes;
	for (int i = 0;i < equation.length();i++)
		if (equation[i] == target) indexes.push_back(i);
	if (indexes.empty()) return 0;
	else return indexes.back();

}

int CalculatorClass::getSpacesSinceLast(int start) {
	int spaceBetween = 0;
	while (start != equation.length()) { start++; spaceBetween++; }
	return spaceBetween;
}

void CalculatorClass::handleMiscKeys() {
	if (equation.length() > 0 && IsKeyPressed(KEY_BACKSPACE)) {
		if (numbers.size() == 1) {
			updateEquation("", true);	
			numbers.clear();
		}
		else {
			if (equation.back() == '('){
				parenthesiesIndexes.pop_front();
				parenthesies.pop_front();
			}
			else if (equation.back() == ')'){
				parenthesiesIndexes.pop_back();
				parenthesies.pop_back();
			}
			else if(equation.back() == '+' || equation.back() == '-' || equation.back() == '*' || equation.back() == '/')
				operations.pop_back();

				equation.pop_back();
		}
	}
	if (IsKeyPressed(KEY_SPACE)) { updateEquation(" ", false); }
}

char CalculatorClass::getOperatorToOperate(const int start, const int end, int& index) {
	char operation = parenthesies[start + 1];

	for (int i = start; i < end; i++) {
		if (parenthesies[i] == '*' || parenthesies[i] == '/') {
			index = i;
			operation = parenthesies[i];
			parenthesies.erase(parenthesies.begin() + i);
			return operation;
		}
	}

	index = start + 1;
	parenthesies.erase(parenthesies.begin() + 1);// for example '+' this will be deleted
	return operation;
}

double CalculatorClass::mathing() {
	if (numbers.size() < 2) {
		return numbers.front();
	}

	double resultDouble = 0;
	int operationsSize = operations.size();
	for (size_t i = 0; i < operationsSize; i++) {
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
	int operationsSize = operations.size();

	for (size_t i = 0; i < operationsSize; i++) {
		if (parenthesiesIndexes.size() % 2 == 0 && parenthesiesIndexes.size() >= 2) {
			int currOpenningParenthesies = parenthesies.size() / 2;
			while (parenthesies[currOpenningParenthesies] != '(') currOpenningParenthesies--;

			int currClosingParenthesies = parenthesies.size() / 2;
			while (parenthesies[currClosingParenthesies] != ')') currClosingParenthesies++;

			int numberOfOperatorsInParenthesies = (currClosingParenthesies - currOpenningParenthesies) - 1;

			int currMiddleInParenthesiesIndexes = parenthesiesIndexes.size() / 2;

			int digitsInParenthesies = ((parenthesiesIndexes[currMiddleInParenthesiesIndexes] - parenthesiesIndexes[currMiddleInParenthesiesIndexes - 1] - numberOfOperatorsInParenthesies)) - 1;
			for (int start = parenthesiesIndexes.size() / 2;true;start++) {

				if (parenthesies[currOpenningParenthesies + 1] != '+' && parenthesies[currOpenningParenthesies + 1] != '-' &&
					parenthesies[currOpenningParenthesies + 1] != '*' && parenthesies[currOpenningParenthesies + 1] != '/') {
					break;
				}

				int index;
				double num2;
				double num1;
				/*
				
				if (parenthesiesIndexes[0] - 1 < 0) {
					num1 = numbers[parenthesiesIndexes[0]];
					numbers[parenthesiesIndexes[0]] = 9999999999999999999; // Dummy value to avoid out-of-bounds

					num2 = numbers[parenthesiesIndexes[0] + 1];
					numbers.erase(numbers.begin() + parenthesiesIndexes[0] + 1);
				}
				else {
					num1 = numbers[parenthesiesIndexes[currMiddleInParenthesiesIndexes - 1] - 1];
					numbers[parenthesiesIndexes[currMiddleInParenthesiesIndexes - 1] - 1] = 9999999999999999999; // Dummy value to avoid out-of-bounds

					num2 = numbers[parenthesiesIndexes[currMiddleInParenthesiesIndexes - 1]];
					numbers.erase(numbers.begin() + parenthesiesIndexes[currMiddleInParenthesiesIndexes - 1]);
				}

				for(int k = 0;k < numbers.size();k++)
					if(numbers[k] == 9999999999999999999)
						numbers.erase(numbers.begin() + k);
				*/
				
				
					
				
				

				if (currClosingParenthesies > parenthesies.size()) {
					currClosingParenthesies = parenthesies.size() / 2;
					while (parenthesies[currClosingParenthesies] != ')') currClosingParenthesies++;
				}


				char operationChar = getOperatorToOperate(currOpenningParenthesies, currClosingParenthesies,index);

				num1 = numbers[index];
				num2 = numbers[index + 1];

				numbers.erase(numbers.begin() + index + 1);
				numbers.erase(numbers.begin() + index);

				switch (operationChar){
					case '+':
						resultDouble = num1 + num2;
						operations.erase(std::find(operations.begin(), operations.end(), '+'));

						break;
					case '-':
						resultDouble = num1 - num2;
						operations.erase(std::find(operations.begin(), operations.end(), '-'));

						break;
					case '*':
						resultDouble = num1 * num2;
						operations.erase(std::find(operations.begin(), operations.end(), '*'));

						break;
					case '/':
						if (num2 != 0) {
							resultDouble = num1 / num2;
						}
						else {
							resultDouble = 0; // Handle division by zero
						}
						operations.erase(std::find(operations.begin(), operations.end(), '/'));

						break;
					default:
						break;

				}
				numbers.insert(numbers.begin() + currMiddleInParenthesiesIndexes, resultDouble);

			}

			parenthesiesIndexes.erase(parenthesiesIndexes.begin() + currMiddleInParenthesiesIndexes);
			parenthesiesIndexes.erase(parenthesiesIndexes.begin() + currMiddleInParenthesiesIndexes - 1);

			if (parenthesies.size() % 3 == 0) {
				parenthesies.erase(parenthesies.begin() + 0);// (
				parenthesies.erase(parenthesies.begin() + 0);// )
			}
			else {
				for (int j = currOpenningParenthesies + 1,count = 0;count != 2;j--,count++) {
					parenthesies.erase(parenthesies.begin() + j);
				}
			}
		}
		else {
			return false;
		}
	}
}