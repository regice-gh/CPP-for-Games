#include <iostream>

int main() {

	//unsigned char c = 'A';
	//std::cout << c << " size of: " << sizeof(c) << std::endl;
	//int i = c; // widening conversion

	//char b = i;

	//c = i; // narrowing conversion
	//std::cout << c << " size of: " << sizeof(c) << std::endl;
	//c = static_cast<unsigned char>(i); //narrowing conversion
	//std::cout << c << " size of: " << sizeof(c) << std::endl;


	//std::cout << b << " " << c << " " << i << std::endl;


	double d{ 42.99 };
	float f = static_cast<float>(d);
	int i = static_cast<int>(f);
	char c = static_cast<char>(i);
	bool b = static_cast<bool>(c);

	std::cout << "double: " << d << std::endl;
	std::cout << "float: " << f << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "char: " << c << std::endl;
	std::cout << "bool: " << b << std::endl;

	return 0;

	//signed to unsigned almost always require explicit cast 
	//widening to narrowing almost always require explicit cast

}