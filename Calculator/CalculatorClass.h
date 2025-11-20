#pragma once
#include "raylib.h"
#include "Button.h"
#include <string>


class CalculatorClass {
	Button buttons[12];
	std::string equation;
	std::deque<int> numbers;// 1 + 2 * 3 = 6 + 1
	std::deque<char> operations;

public:
	CalculatorClass();	

	void drawButtons();

	void handleButtonClicks();

	void showEquation();

	void updateEquation(const std::string &newEquation,bool equalsTriggerd) {
		if(equalsTriggerd)
			equation = newEquation + " ";
		else
			equation += newEquation + " ";
	}

};
