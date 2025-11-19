#pragma once
#include "raylib.h"
#include <string>

class Button {
private:
	Rectangle button;
	char buttonSymbol;
	std::pair<Color,Color> buttonColors;

public:
	Button() {}
	Button(const float &x,const float &y,const char & buttonSymbol) {
		button.x = x;
		button.y = y;
		button.width = 80;
		button.height = 80;
		this->buttonSymbol = buttonSymbol;

		buttonColors.first = BLACK;
		buttonColors.second = GREEN;

	}
	void drawButton() {
		DrawRectangleRec(button, buttonColors.first);
		DrawRectangleLinesEx(button, 5, GREEN);
		DrawText(std::to_string(buttonSymbol).c_str(), button.x + 30, button.y + 20, 40, buttonColors.second);

	}
	bool isClicked() {
		if (CheckCollisionPointRec(GetMousePosition(), button)) {
			buttonColors.first = GREEN;
			buttonColors.second = BLACK;

			return  true;
		}
		else {
			buttonColors.first = BLACK;
			buttonColors.second = GREEN;

			return false;
		}
	}

	int getSymbol() const {
		return buttonSymbol;
	}
};