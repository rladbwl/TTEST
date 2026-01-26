#include <iostream>

class Entity
{	
public:
	//정답 
	//int GetX() const { return x; }
	
	friend void ShowEntity(Entity& entity)
	{
		std::cout << entity.x << "," << entity.y << "\n"; // 선언도 구현도 내부에서 해도 가능함 이상한거임 쓰는거 권장하지 않음 다른곳에서 보고 해석이 가능할 수 잇도록
	}

	friend void Add(Entity& entity1, Entity& entity2)
	{
		entity1.x + entity2.x;
		entity1.y + entity2.y; //이게 왜 잘못된 함수인지 ㅜㄹ어본다고??
	}

	//접근한정자/제한자(visivility)
private:
	int x = 0;
	int y = 0;
};



//Entity 정보를 출력하는 함수
//void ShowEntity(Entity& entity)
//{
//	std::cout << entity.x << "," << entity.y << "\n";
//}

int main() 
{
	Entity entity1;
	Entity entity2;
	Add(entity1,entity2);
	//entity1.Add(entity2);
	//entity.ShowEntity(entity);
	//ShowEntity(entity1);

	std::cin.get();
}