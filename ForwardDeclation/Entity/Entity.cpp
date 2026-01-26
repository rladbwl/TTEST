#include "Entity.h"
#include "../Vector.h"
#include <iostream>

Entity::Entity(int x, int y)
{
	position = new Vector();
	position->x = x;
	position->y = y; 
}
Entity::Entity(const Entity& other)
{
	std::cout << "copy constructor called\n";

	//기본 복사 생성자가 하는 일
	//값 복사
	//나중에 댕글링 포인터 문제 발생
	//댕글링(Dangling) - 주인을 잃어버림
	//->이미 삭제된 메모리 주소에 접근
	//position = other.position; //position이 가지고 있는 주소 값을 복사한거임 main에 entity, entity2가 있음 두개다 같은 공간을 가리킴 entity가 먼저 회수됨 entity2가 지우려고 해서 보면 이미 지워져있음?? entity2는 주소메모리를 가지고 있음 
							   //이걸 해결하려고 나온게 가비지컬렉터인데 c++에는 없고 스마트포인터/컬렉터인가?? 가 있음
							   //weekptr?? 유니크ptr?? 소유권을 쉐어드ptr?? 소유권을 공유할거냐 독점할거냐 둘중하나다 뭐에대한 설명인건지는 모르것음

	//깊은 복사(Deep copy)
	//공간 확보.
	position = new Vector();

	//값 복사
	position->x = other.position->x;
	position->y = other.position->y;
}

Entity::~Entity(){

	if (position){
		delete position;
	    position = nullptr;
	}
}