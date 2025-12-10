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
	Button() = default;
	Button(const float& x, const float& y, const std::string& buttonSymbol, const float& buttonWidth, const float& buttonHeight) {
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
		button.width = 80.0f;
		button.height = 80.0f;
		this->buttonSymbol[0] = buttonSymbol;

		buttonColors.first = BLACK;
		buttonColors.second = GREEN;

	}
	void drawButton(){
		DrawRectangleRec(button, buttonColors.first);
		DrawRectangleLinesEx(button, 5.0f, GREEN);

		if (buttonSymbol.length() >= 3.0) {
			// long symbols
			if (buttonSymbol == "complex \n  mode") {
				DrawText(buttonSymbol.c_str(), button.x + 10.0f, button.y + 20.0f, 18.0f, buttonColors.second);
			}
			if (buttonSymbol == "sin") {
				DrawText(buttonSymbol.c_str(), button.x + 15.0f, button.y + 20.0f, 40.0f, buttonColors.second);
			}
			if (buttonSymbol == "cos") {
				DrawText(buttonSymbol.c_str(), button.x + 6.0f, button.y + 20.0f, 40.0f, buttonColors.second);
			}
			if (buttonSymbol == "tan") {
				DrawText(buttonSymbol.c_str(), button.x + 8.0f, button.y + 20.0f, 40.0f, buttonColors.second);
			}
			if (buttonSymbol == "log") {
				DrawText(buttonSymbol.c_str(), button.x + 14.0f, button.y + 20.0f, 40.0f, buttonColors.second);
			}
			if (buttonSymbol == "rad") {
				DrawText(buttonSymbol.c_str(), button.x + 6.0f, button.y + 20.0f, 40.0f, buttonColors.second);
			}
		}
		else {
			// small symbols
			if (buttonSymbol[0] >= 0 && buttonSymbol[0] <= 10) {
				DrawText(std::to_string(buttonSymbol[0]).c_str(), button.x + 30.0f, button.y + 20.0f, 40.0f, buttonColors.second);
			}
			else {
				DrawText(buttonSymbol.c_str(), button.x + 30.0f, button.y + 20.0f, 40.0f, buttonColors.second);
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

	double getSymbol() const {
		if (buttonSymbol[0] > '0' && buttonSymbol[0] < '10') {
			return buttonSymbol[0];
		}
		if(buttonSymbol == "pi") {
			return 3.14;
		}
		if (buttonSymbol[0] == 'e') {
			return 2.71;
		}
		
	}
};