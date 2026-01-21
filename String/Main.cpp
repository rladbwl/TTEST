#include <iostream>

//클래스 내부에서 문자열 다루기
class Player
{
	//위에 멤버변수
	//그 아래에 함수
public:
	//생성자
	//객체를 생성할 때 호출 되는 특별한 함수
	//반환형이 없고, 클래스 이름과 동일
	Player(const char* inName) 
	{
		//문자열 복사
		//name = inName;
		
		//1.저장 공간 확보
		// -> 확보할 공간의 크기를 알아야 함
		//strlen은 0을 만날때까지의 수를 확인한다 우리는 0문자를 포함해야 되는 크기라서 +1해줘야함
		size_t length = strlen(inName)+1;
		name = new char[length];

		//2. 문자열 복사
		//memcpy()과 같다
		strcpy_s(name, length, inName);

	};

	//소멸자
	//객체가 해제될 때 실행
	~Player()
	{
		if (name) // != nullptr
		{
			delete[] name;
			name = nullptr; //이렇게 까지 해줘야 좋음
		}
	}

private:
	//문자열을 저장할 변수
	char* name = nullptr;
};

int main()
{
	//문자열은 불변성을 가짐
	const char* testString = "yujin";
	std::cout << testString << "\n";

	//문자 배열도 가능
	char buffer[6] 
		= { 'Y','u','j','i','n','\0'};
	std::cout << buffer << "\n";

	//객체 기반으로 문자열 사용
	Player player("yujin");




	std::cin.get();



}