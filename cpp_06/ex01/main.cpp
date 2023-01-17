#include "serialization.hpp"

uintptr_t serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}

int main(void)
{
	Data data1;

	data1.myInt = 10;
	data1.myChar = 'z';
	data1.myFloat = 0.123456;

	std::cout << &data1 << std::endl;
	std::cout << deserialize(serialize(&data1)) << std::endl;

	std::cout << data1.myInt << std::endl;
	std::cout << deserialize(serialize(&data1))->myInt << std::endl;

	std::cout << data1.myChar << std::endl;
	std::cout << deserialize(serialize(&data1))->myChar << std::endl;

	std::cout << data1.myFloat << std::endl;
	std::cout << deserialize(serialize(&data1))->myFloat << std::endl;

	return 0;
}
