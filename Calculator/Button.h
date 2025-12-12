#pragma once
#include "raylib.h"

#include <string>
#include <stack>
#include <cmath>

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
			if (buttonSymbol == "x^2") {
				DrawText("x", button.x + 25.0f, button.y + 20.0f, 40.0f, buttonColors.second);
				DrawText("2", button.x + 50.0f, button.y + 13.0f, 20.0f, buttonColors.second);
			}
			if (buttonSymbol == "root") {
				DrawText("|", button.x + 30.0f, button.y + 24.0f, 35.0f, buttonColors.second);
				DrawText("\\", button.x + 16.0f, button.y + 34.0f, 22.0f, buttonColors.second);
				DrawText("_", button.x + 33.0f, button.y + 1.0f, 35.0f, buttonColors.second);
				DrawText("_", button.x + 39.0f, button.y + 1.0f, 35.0f, buttonColors.second);
				DrawText("_", button.x + 10.0f, button.y + 23.0f, 20.0f, buttonColors.second);

				DrawText("x", button.x + 39.0f, button.y + 25.0f, 35.0f, buttonColors.second);
			}
			if (buttonSymbol == "e^2") {
				DrawText("e", button.x + 25.0f, button.y + 20.0f, 40.0f, buttonColors.second);
				DrawText("2", button.x + 50.0f, button.y + 13.0f, 20.0f, buttonColors.second);
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

	std::string getSymbol() const {
		if (buttonSymbol[0] == 'e') {
			return "2.7182818284";
		}
		if (buttonSymbol == "pi") {
			return "3.1415926535";
		}



		return buttonSymbol;
	}
};