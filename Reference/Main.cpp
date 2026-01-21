#include <iostream>

//Call-By-Reference
//참조에 의한 호출
// 참조=주소 -> 주소 값 복사.
// void Increment(int* value)
// {
// 	++(*value);
// }

void Increment(int& value)
{
	++value;
 }

int main()
{
	// int a = 5;
	// int& ref = a;	// L-Value Reference
	// ref = 10;

	int number = 10;
	Increment(number);

	std::cin.get();
}