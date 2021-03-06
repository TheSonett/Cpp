#include <iostream>
#include <memory>

class Entity {
private:
	int age;
public:
	Entity() {
		std::cout << "Object Created!" << std::endl;
	}

	~Entity() {
		std::cout << "Object Destroyed!" << std::endl;
	}

	void printSomething() {
		std::cout << "It is printing something\n";
	}

	void setValue(std::unique_ptr<Entity>& entity) {
		entity->age = 24;
		std::cout << entity->age << std::endl;
	}
};



int main()
{
	std::unique_ptr<Entity> e1;
	{
		std::unique_ptr<Entity> entity = std::make_unique<Entity>();
		entity->setValue(entity);
	}

	std::cin.get();
}