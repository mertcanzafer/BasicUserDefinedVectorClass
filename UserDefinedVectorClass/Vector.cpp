#include "Vector.h"
using namespace VNS;

Vector::Vector()
	:Array{ nullptr },size{0}, capacity{5}
{
	Array = new int32_t[capacity];
}

Vector::Vector
(
	int32_t elements, int32_t value
):Vector()
{
	size = elements;
	capacity += elements; 
	Array = new int32_t[capacity];

	for (size_t i = 0; i < size; i++)
	{
		Array[i] = value;
	}

}

Vector::Vector(const Vector& copy)
	:size{copy.size},capacity{copy.capacity}
{
	if (copy.Array == nullptr) throw "Exception";

	Array = new int32_t[capacity];

	for (size_t i{ 0 }; i < copy.size; i++)
	{
		Array[i] = copy.Array[i];
	}
}

void Vector:: push_back(int32_t value)
{
	Array[size] = value;
	size++;
}

bool VNS::Vector::operator==(const Vector& rhs) const
{
	if (this->size != rhs.size) return false; // both sizes should be identical

	for (size_t i = 0; i < this->size; i++)
	{
		if (this->Array[i] != rhs.Array[i])
		{
			return false;
		}
	}
	return true;
}

bool Vector::operator!=(const Vector& rhs) const
{
	return !(*this == rhs);
}

Vector::~Vector()
{
	delete[] Array;
}

std::ostream& VNS::operator<<(std::ostream& os, const Vector& rhs)
{
	for (size_t i = 0; i < rhs.size; i++)
	{
		os << rhs.Array[i] << " ";
	}

	os << " || ";

	for (size_t i = rhs.size; i < rhs.capacity; i++)
	{
		os << rhs.Array[i] << " ";
	}

	os << std::endl;
	return os;
}
