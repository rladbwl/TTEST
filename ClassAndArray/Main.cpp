#include <iostream>
//연습문제 4 https://resonant-exception-448.notion.site/1-2c07519ce7cb81e387c8c8853b50cc49
//클래스
// 
//게임물체(객체)
//Game-Object / Actor / Entity(개체)
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

	const Entity* GetSelf() const //뒤에 const붙이려면 앞에도 붙여야하는데 어디 다른곳에서는 그냥 뒤에만 붙엿엇음 왜그런지 알아보기
	{
		//this는 자기 자신을 가리키는 포인터
		return this;
	}
};
//void SafeDelete() {
//
//}//못씀 ㅜ

int main()
{
	//****아래가 실행될까?****됨 왜되는지 알아보기 /  엔진 개발팀 문제
	// C++이 컴파일 될때 C문법처럼 된다????
	//Entity* entity = nullptr; //객체호출할때 null체크는 함수호출할때 안한다????
	//entity->ShowName(); //이게 왜 되는지 중요함!

	//const int count = 5;
	//Entity entities[count];
	
	//함수호출
	//Range-Based Loop (foreach) 이거 아래 함수호출부분 주석처리해둠
	//for (const Entity& entity : entities)
	//{
	//	entity.ShowName(); // 함수에 const붙여줬기때문에 entity에 빨간줄 사라짐
	//}

	//객체포인터배열 파트
	/////////const int count = 5;
	/////////Entity* entities[count] = {}; // ={}; 0으로 셋팅 이렇게 할 수 있음
//	/////////memset(entities, 0, sizeof(Entity*) * count); //빠른편. 이것도 유용한 함수 알아두기 
	/////////
	/////////for (int ix = 0; ix<count; ix++)//후위일시 예전엔 차이가 있었는데
	/////////{
	/////////	entities[ix] = new Entity(); //entities변수는 스택임 하지만 이 변수가 클래스에 들어가면 스택이랑 힙 둘다 존재한다????
	/////////}
	/////////for (Entity*& entity : entities) 
	/////////{
	/////////	//SafeDelete(entity);
	/////////	delete entity;
	/////////	entity = nullptr;
	/////////} //이것도 꼬아서 내는 문제?? delete 까지는 되는데 nullptr까지 영향이 안감 그래서 뭐 참조를 해줘야 한다???? 같은주소를 저장하고 있을뿐 다른 변수다

	Entity* entity = new Entity();
	std::cout << entity << "\n";
	std::cout << entity->GetSelf() << "\n";
	delete entity;

	std::cin.get();
}