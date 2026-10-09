#include <iostream>
#include <string>
#include "Array.hpp"

int main( void )
{
	Array<int> empty;
	std::cout << "empty size: " << empty.size() << std::endl;

	Array<int> a(5);
	std::cout << "a size: " << a.size() << ", a[0] = " << a[0] << std::endl;

	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = i * 10;
	std::cout << "a[3] = " << a[3] << std::endl;

	Array<int> b(a);
	b[0] = 999;
	std::cout << "a[0] = " << a[0] << ", b[0] = " << b[0] << std::endl;

	Array<int> c;
	c = a;
	c[1] = 555;
	std::cout << "a[1] = " << a[1] << ", c[1] = " << c[1] << std::endl;

	try
	{
		a[5] = 1;
	}
	catch (std::exception & e)
	{
		std::cout << "a[5]: " << e.what() << std::endl;
	}
	try
	{
		a[-1] = 1;
	}
	catch (std::exception & e)
	{
		std::cout << "a[-1]: " << e.what() << std::endl;
	}

	const Array<int> k(a);
	std::cout << "k[2] = " << k[2] << std::endl;

	Array<std::string> s(2);
	s[0] = "hello";
	s[1] = "world";
	std::cout << s[0] << " " << s[1] << std::endl;

	return 0;
}