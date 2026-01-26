	#include <iostream>
	#include "Entity/Entity.h" // Entity폴더 안에 있는거를 찾음 상대경로

	void TestFunction(Entity entity)
	{
		std::cout << "Testfunction"; //이것도 복사된다고 한건가?
	}
	

	int main()
	{
		Entity entity(10, 20);
		Entity entity2(entity);
		Entity entity3 = entity2; // 이럴때도 복사생성자가 호출됨

		TestFunction(entity3);

		std::cin.get();
	}