#include <iostream>
#include "Player.h"

int main()
{
	Player player1;
	player1.Move(1, 2);

	Player* player2 = new Player;
	player2->Move(2, 3);
	delete player2;
	player2 = nullptr;
}