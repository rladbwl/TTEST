#pragma once

class Player
{
	//클래스 내부의 속성을 어디까지 노출 시킬지 결정
	//public공개 / protecteb상속(물려줌)계층까지 / private나만
public:

	//생성자
	//파라미터를 받지 않는 생성자 = 기본 생성자
    //Player() = default; //명시적으로 더 정확하게 {} 이렇게만 해두면 코드를 덜쓴 느낌이 남
	//~Player() = default; //소멸자도 마찬가지
	Player();
	Player(const char* inName); // 생성자 추가
	~Player();

	//클래스 조작 함수
	void Move(int inX, int inY);
	//	{
	//		x = inX;
	//		y = inY;
	//	}
private:
	int x = 0;
	int y = 0;
	int speed = 0;

	//이름 값(문자열)
	//객체를 만들기 전에 name값에 뭐가 올지 모르기 때문에 힙을 사용
	//char name[10] = {}; 이렇게도 할 수 있음
	char* name = nullptr;

}; 
