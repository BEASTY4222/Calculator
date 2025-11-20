#pragma once
#include "raylib.h"
#include "Button.h"
#include <string>


class CalculatorClass {
	Button buttons[13];
	std::string equation;
	std::deque<int> numbers;// 1     2   3 = 6 + 1
	std::deque<char> operations;// +   *   =

public:
	CalculatorClass();	

	void drawButtons();

	void handleButtonClicks();

	void showEquation();

	void updateEquation(const std::string& newEquation, bool equalsTriggerd); 

	void getNumbers(const std::string &equation);

	void handleMiscKeys();
};
