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
):size{0},capacity{5},Array{nullptr}
{
	size = elements;
	capacity += elements; 
	Array = new int32_t[capacity];

	for (size_t i = 0; i < size; i++)
	{
		Array[i] = value;
	}

}

Vector::Vector(const std::initializer_list<int32_t>& list)
	:size{ 0 }, capacity{ 0 }, Array{ nullptr }
{
	capacity = static_cast<uint32_t>(list.size()) + 5;
	Array = new int32_t[capacity];

	for (auto& i : list)
	{
		push_back(i);
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
	if (size < capacity)
	{
		Array[size] = value;
		size++;
	}
	else {
		capacity *= 2;
		int32_t* newAray = new int32_t[capacity];

		for (size_t i = 0; i < size; i++)
		{
			newAray[i] = Array[i];
		}
		delete[] Array;

		Array = newAray;
		newAray = nullptr;
		Array[size] = value;
		size++;
	}
}

void Vector::pop_back()
{
	if (IsEmpty()) { throw std::exception("Vector is empty already!!!"); }
	size--;
}

void Vector::insert(int32_t index, int32_t value)
{
	if (index < 0 || index >= size) throw std::exception("Out of bound!!!");

	if (size < capacity)
	{
		for (int i = size; i > index; i--)
		{
			Array[i] = Array[i - 1];
		}

		Array[index] = value;
		size++;
	}

	else 
	{
		capacity *= 2;
		int32_t* newArray = new int32_t[capacity];

		for (int i = 0; i < size; i++)
		{
			newArray[i] = Array[i];
		}
		delete[] Array;

		Array = newArray;
		newArray = nullptr;

		for (int i = size; i > index; i--)
		{
			Array[i] = Array[i - 1];
		}

		Array[index] = value;
		size++;
	}
}

void Vector::erase(uint32_t index)
{
	if (index < 0 || index >= size) throw std::exception("Index out of range");
	for (int i = index; i < size; i++)
	{
		Array[i] = Array[i + 1];
 	}
	size--;
}

void VNS::Vector::clear()
{
	size = 0;
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

Vector& Vector::operator=(const Vector& rhs)
{
	if (rhs.size > this->size)
	{
		size = rhs.size;
		capacity = rhs.capacity;
		delete[] Array;
		Array = new int32_t[rhs.capacity];
	}

	for (int i = 0; i < rhs.size; i++)
	{
		Array[i] = rhs.Array[i];
	}
	return *this;
}

int& Vector::operator[](uint32_t index)
{
	return Array[index];
}

int& Vector::at(uint32_t index)
{
	if (size < 0 || index >= size) throw std::exception("Out of bound Exception!!");

	return Array[index];
}

int& Vector::front()
{
	return Array[0];
}

int& Vector::back()
{
	return Array[size - 1];
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
