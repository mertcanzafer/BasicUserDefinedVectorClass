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

	VNS::Vector vec3{ 1,2,3,4,5,5,6,7 };
	std::cout << vec3 << std::endl;

	while (!vec3.IsEmpty())
	{
		vec3.pop_back();
		std::cout << vec3;
	}
	try {
		vec3.pop_back();
	}
	catch (std::exception& ex)
	{
		std::cout << "Exception handled!!" << std::endl;
	}

	vec = vec3;
	std::cout << vec << std::endl;

	std::cout <<"Size = " << vec.getSize()<<std::endl;

	vec.insert(0, 1);
	
	std::cout << vec << std::endl;

	vec.erase(0);

	std::cout << vec << std::endl;
	std::cout << "Size = " << vec.getSize() << std::endl;

	return 0;
}