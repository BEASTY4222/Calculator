#pragma once
#include "raylib.h"
#include <string>
#include <stack>

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
	void drawButton(){
		DrawRectangleRec(button, buttonColors.first);
		DrawRectangleLinesEx(button, 5, GREEN);
		if (buttonSymbol >= 0 && buttonSymbol <= 10) {
 			DrawText(std::string(1,'0' + buttonSymbol).c_str(), button.x + 30, button.y + 20, 40, buttonColors.second);
		}
		else{
			DrawText(std::string(1, buttonSymbol ).c_str(), button.x + 30, button.y + 20, 40, buttonColors.second);
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
		if (buttonSymbol > '0' && buttonSymbol < '10') {
			return buttonSymbol;
		}
		
	}
};