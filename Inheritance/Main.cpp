#include <iostream>
//클래스상속

class Entity
{
public:
	Entity()
	{
		std::cout << "Entity() called\n";
	}
	~Entity()
	{
		std::cout << "~Entity() called\n";
	}
private:
	float x = 0.0f;
	float y = 0.0f;
};

class Player : public Entity
{
public:
	Player()
	{
		std::cout << "Entity() called\n";
	}
	~Player()
	{
		std::cout << "~Entity() called\n";
	}

private:
	char* name = nullptr;
};

int main()
{
	Player player;

	std::cin.get();
}