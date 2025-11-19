#pragma once
#include "raylib.h"
#include "Button.h"
#include <string>


class CalculatorClass {
	Button buttons[12];
	std::string equation;

public:
	CalculatorClass();	

	void drawButtons();

	inline void handleButtonClicks() {
		for (int i = 0; i < 12; i++) {
			if (buttons[i].isClicked()) {
				updateEquation(std::to_string(buttons->getSymbol()));
			}
		}
	}

	void showEquation();

	void updateEquation(const std::string &newEquation) {
		equation = newEquation;
	}

};
