#include <iostream>
#include "Player.h"

//Player:: <- Player 클래스 안에 있는
//:: <- 범위 지정 연산자

int main()
{
	////인스턴스/객체
	Player player1;
	player1.Move(5, 2);

	//힙
	Player* player2 = new Player("yujin");
	player2->Move(3, 1);
	//(*player2).Move(3, 1);
	delete player2;
	player2 = nullptr;

	std::cin.get();
}