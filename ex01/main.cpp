#include <iostream>
#include <string>
#include "iter.hpp"

void increment(int & x) { x++; }

template <typename T>
void print(const T & x) { std::cout << x << std::endl;}

int main( void )
{
	int arr[3] = {1, 2, 3};
	iter(arr, 3, increment);          // modifies elements
	iter(arr, 3, print<int>);         // 2 3 4

	const int carr[3] = {10, 20, 30};
	iter(carr, 3, print<int>);        // const array, read only

	std::string strs[2] = {"hello", "world"};
	iter(strs, 2, print<std::string>);

	// iter(carr, 3, increment);      // uncomment: must NOT compile

	return 0;
}