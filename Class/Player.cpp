#include <iostream>
#include "Player.h"



Player::Player(const char* inName)
	// :x(0), y(0), speed(0); 이렇게도 쓸 수 있음(멤버이니셜라이져?이건강?)
{
	//동적 할당 및 문자열 복사
	size_t length = strlen(inName) + 1;
	name = new char[length];

	//복사처리
	strcpy_s(name, length, inName);

}
//기본값 설정/자원 할당
Player::Player()
{

}
//자원해제
Player::~Player()
{
	//null 체크 name에 뭐든 있으면 delete 여기서 null체크하는 이유 알아보기
	if (name)
	{
		delete[] name;
		name = nullptr;
	}
}
void Player::Move(int inX, int inY)
{
	x = inX;
	y = inY;
}