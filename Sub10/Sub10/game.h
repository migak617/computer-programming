#pragma once
#include <windows.h>
#include <iostream>

using namespace std;

class Game {
private:
	int x;
	int y;
	int direction;

	void gotoXY(int x, int y) {
		COORD pos = { x,y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}
public:
	Game() {
		x = 5;
		y = 5;
		direction = 0;
	}
	void setDirection(int i) {
		direction = i;
	}
	void move() {
		if (direction == 37) {
			x--;
		}
		else if (direction == 38) {
			y--;
		}
		else if (direction == 39) {
			x++;
		}
		else if (direction == 40) {
			y++;
		}
		system("cls");
		this->gotoXY(x, y);
		cout << x << " " << y;
		cout << "во?";
	}
};