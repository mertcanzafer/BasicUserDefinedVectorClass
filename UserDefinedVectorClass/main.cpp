#include <iostream>
#include "Vector.h"

int main()
{
	VNS::Vector vec(11);
	std::cout << vec<<std::endl;

	vec.push_back(1);
	std::cout << vec << std::endl;
	vec.push_back(2);
	std::cout << vec << std::endl;
	vec.push_back(3);
	std::cout << vec << std::endl;
	vec.push_back(4);
	std::cout << vec << std::endl;
	vec.push_back(5);
	std::cout << vec << std::endl;

	VNS::Vector vec2{ vec };
	std::cout << vec2 << std::endl;

	std::cout << ((vec == vec2) ? "Yes, They are equal" : "No, They are not equal")<<std::endl;

	std::cout << ((vec.IsEmpty()) ? "The vector is empty" : "No, the vector is not empty")<<std::endl;

	return 0;
}