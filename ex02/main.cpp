#include <iostream>
#include <string>
#include "Array.hpp"

template <typename T>
void printArray(const Array<T> & arr)
{
	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << "(size " << arr.size() << ")" << std::endl;
}

template <typename T>
void tryAccess(Array<T> & arr, unsigned int i)
{
	try
	{
		std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "arr[" << i << "] -> exception: " << e.what() << std::endl;
	}
}

int main( void )
{
	std::cout << "--- empty array ---" << std::endl;
	Array<int> empty;
	printArray(empty);
	tryAccess(empty, 0);

	std::cout << "--- Array(0) ---" << std::endl;
	Array<int> zero(0);
	printArray(zero);
	tryAccess(zero, 0);

	std::cout << "--- default values ---" << std::endl;
	Array<int> a(5);
	printArray(a);

	std::cout << "--- fill and read ---" << std::endl;
	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = i * 10;
	printArray(a);

	std::cout << "--- copy is independent ---" << std::endl;
	Array<int> b(a);
	b[0] = 999;
	printArray(a);
	printArray(b);

	std::cout << "--- assignment is independent ---" << std::endl;
	Array<int> c;
	c = a;
	c[1] = 555;
	printArray(a);
	printArray(c);

	std::cout << "--- self assignment ---" << std::endl;
Array<int> & ref = a;
a = ref;
printArray(a);

	std::cout << "--- out of bounds ---" << std::endl;
	tryAccess(a, 4);
	tryAccess(a, 5);
	tryAccess(a, -1);	// becomes UINT_MAX, caught by the same check

	std::cout << "--- const array ---" << std::endl;
	const Array<int> k(a);
	std::cout << "k[2] = " << k[2] << std::endl;

	std::cout << "--- strings ---" << std::endl;
	Array<std::string> s(2);
	s[0] = "hello";
	s[1] = "world";
	printArray(s);

	return 0;
}