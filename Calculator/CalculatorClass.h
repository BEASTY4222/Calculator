#pragma once
#include "raylib.h"
#include "Button.h"
#include <string>
#include <algorithm>
#include <deque>


class CalculatorClass {
	Button buttons[40];
	std::string equation;
	std::deque<double> numbers;// 1     2   3   6   1   7
	std::deque<char> operations;//   +    *   =   +   =
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

	int getLatestIndexFromEquation(const char & target);

	int getSpacesSinceLast(int start);

	void handleMiscKeys();

	char getOperatorToOperate(const int start, const int end, int &index);

	void push_back_within_parenthesies(const char& op);

	double mathing();

	void getNumbers(const std::string& equation);

	bool parenthesiesMathing();
};
