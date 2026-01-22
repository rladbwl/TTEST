#include <iostream>



//객체기반 문자열 복사
class People
{
public:
	People(const char* inName)
	{
		//문자열 크기 반환?
		size_t length = strlen(inName) + 1;
		name = new char[length];

		//문자열 복사
		strcpy_s(name, length, inName);


	}
	void PrintName() {
		std::cout << name;
	}

	~People(){
		if (name) {
			delete[] name;
			name = nullptr;
}
	}

private:
	char* name = nullptr;
};

int main()
{
	People people("yujin");
}