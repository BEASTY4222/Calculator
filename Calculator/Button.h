#pragma once
#include "raylib.h"
#include <string>
#include <stack>

class Button {
private:
	Rectangle button;
	std::string buttonSymbol;
	std::pair<Color,Color> buttonColors;
	

public:
	Button() {}
	Button(const float& x, const float& y, const std::string& buttonSymbol, const int& buttonWidth, const int& buttonHeight) {
		button.x = x;
		button.y = y;
		button.width = buttonWidth;
		button.height = buttonHeight;
		this->buttonSymbol = buttonSymbol;

		buttonColors.first = BLACK;
		buttonColors.second = GREEN;
	}
	Button(const float &x,const float &y,const char & buttonSymbol) {
		button.x = x;
		button.y = y;
		button.width = 80;
		button.height = 80;
		this->buttonSymbol[0] = buttonSymbol;

		buttonColors.first = BLACK;
		buttonColors.second = GREEN;

	}
	void drawButton(){
		DrawRectangleRec(button, buttonColors.first);
		DrawRectangleLinesEx(button, 5, GREEN);
		if (buttonSymbol.length() > 5) {
			DrawText(buttonSymbol.c_str(), button.x + 15, button.y + 30, 23, buttonColors.second);
		}
		else {
			if (buttonSymbol[0] >= 0 && buttonSymbol[0] <= 10) {
				DrawText(std::to_string(buttonSymbol[0]).c_str(), button.x + 30, button.y + 20, 40, buttonColors.second);
			}
			else {
				DrawText(buttonSymbol.c_str(), button.x + 30, button.y + 20, 40, buttonColors.second);
			}
		}
	}
	bool isClicked() {
		if (CheckCollisionPointRec(GetMousePosition(), button)) {
			buttonColors.first = GREEN;
			buttonColors.second = BLACK;

			return IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
		}
		else {
			buttonColors.first = BLACK;
			buttonColors.second = GREEN;

			return false;
		}
	}

	int getSymbol() const {
		if (buttonSymbol[0] > '0' && buttonSymbol[0] < '10') {
			return buttonSymbol[0];
		}
		
	}
};