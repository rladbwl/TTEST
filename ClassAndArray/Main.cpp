#include <iostream>
//연습문제 4 https://resonant-exception-448.notion.site/1-2c07519ce7cb81e387c8c8853b50cc49
//클래스
class Entity
{
public:

	Entity()
	{
		std::cout << "Constructor called\n";

	}
	//기본 소멸자
	~Entity() {};

	void ShowName() const // 함수를 상수형으로 변경 / 함수끝에 const를 지정하면, 함수 본문에서 객체 내부의 값을 변경할 수 없음
	{					  // const는 안전장치로 업계에서 추천하는 방법
		std::cout << "Entity.\n";
	}
};

int main()
{
	//****아래가 실행될까?****됨 왜되는지 알아보기 /  엔진 개발팀 문제
	// C++이 컴파일 될때 C문법처럼 된다????
	// C++ -> 
	Entity* entity = nullptr; //객체호출할때 null체크는 함수호출할때 안한다????
	entity->ShowName(); //이게 왜 되는지 중요함!

	const int count = 5;
	Entity entities[count];
	
	//함수호출
	//Range-Based Loop (foreach)
	for (const Entity& entity : entities)
	{
		entity.ShowName(); // 함수에 const붙여줬기때문에 entity에 빨간줄 사라짐
	}

	std::cin.get();
}