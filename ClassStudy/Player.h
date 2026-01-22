#pragma once

class Player{

public:
	Player();
	~Player();
	void Move(int inX, int inY);

private:
	int x = 0;
	int y = 0;
};