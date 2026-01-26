#include <iostream>
//매크로 안에서 어떤 항목 앞에 #을 붙이면
//무지성(무조건) 으로 문자열로 변환함
#define NAME(x) #x
#define PURE = 0;

//순수 가상 함수를 가지는 클래스
//인터페이스
//순수 가상 함수만 가져야 함
class NameInterface
{
public:	//외부에서 접근 가능해야 인터페이스가 의미가 있다
	//순수 가상 함수 (Pure)
	virtual const char* GetName() const = 0;
	//virtual const char* GetName() const PURE;
};

class Entity : public NameInterface  //NameInterface->Entity->Player
{																											
public:
	//const char* GetName() const { return "Entity"; }
	virtual const char* GetName() const override //virtual이 추가되면 가상환경테이블이 추가된다
	{ 
		return NAME(Entity); 
	} 
};

class Player : public Entity
{
public:
	Player(const char* name)
	{
		//내부의 name설정 크기
		size_t length = strlen(name) + 1;
		//할당
		this->name = new char[length]; //this도 포인터 변수
		//문자열 복사
		strcpy_s(this->name, length, name);
	}
	~Player()
	{
		if (name)
		{
			delete[] name;	//현재 name이 가지고 있는 성질이 배열이기때문에
			name = nullptr;
		}
	}
	virtual const char* GetName() const override { return name; } //오버라이드는 꼭하장 오타방지

private:
	char* name = nullptr;
};

int main()
{
	Entity* entities[250] = {}; 

	Entity* entity = new Entity();
	std::cout << entity->GetName() << "\n";
	entities[0] = entity;

	Player* player = new Player("yujin");
	//Entity* player = new Player("yujin");
	std::cout << player->GetName() << "\n";
	//entities[1] = player;

	//NameInterface* test = new NameInterface;

	delete player;
	delete entity;
	std::cin.get();
}