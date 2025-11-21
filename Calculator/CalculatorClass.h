#pragma once
#include "raylib.h"
#include "Button.h"
#include <string>


class CalculatorClass {
	Button buttons[20];
	std::string equation;
	std::deque<double> numbers;// 1     2   3 = 6   1
	std::deque<char> operations;//   +    *   =   +
	bool firstParenthesis;


public:
	CalculatorClass();	

	void drawButtons();

	void handleButtonClicks();

	void showEquation();

	void updateEquation(const std::string& newEquation, bool equalsTriggerd); 

	void getNumbers(const std::string &equation);

	void handleMiscKeys();
};
