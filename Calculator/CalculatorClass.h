#pragma once
#include "raylib.h"
#include "Button.h"
#include <string>


class CalculatorClass {
	Button buttons[40];
	std::string equation;
	std::deque<double> numbers;// 1     2   3   6   1
	std::deque<char> operations;//   +    *   =   +
	std::deque<int> parenthesiesIndexes;
	std::deque<char> parenthesies;
	bool firstParenthesis;
	bool complexMode;


public:
	CalculatorClass();	

	void drawButtons();

	void handleButtonClicks();

	void showEquation();

	void updateEquation(const std::string& newEquation, bool equalsTriggerd); 

	void getNumbers(const std::string &equation);

	int getIndexFromEquation(const char & target);

	void handleMiscKeys();

	double mathing();

	bool parenthesiesMathing();
};
