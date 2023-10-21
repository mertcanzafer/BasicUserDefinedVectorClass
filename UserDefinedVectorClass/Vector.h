#pragma once

#include <iostream>

namespace VNS
{
	typedef signed char        int8_t;
	typedef short              int16_t;
	typedef int                int32_t;
	typedef long long          int64_t;
	typedef unsigned char      uint8_t;
	typedef unsigned short     uint16_t;
	typedef unsigned int       uint32_t;
	typedef unsigned long long uint64_t;

	class Vector
	{
	   public:
		   Vector();
		   Vector(int32_t elements, int32_t value = 0);
		   Vector(const std::initializer_list<int32_t>& list);

		   void push_back(int32_t value);
		   void pop_back();
		   void insert(int32_t index, int32_t value);
		   void erase(uint32_t index);
		   void clear();

		   inline bool IsEmpty()const { return (size == 0); };
		   inline uint32_t getSize()const { return size; }
		   inline uint32_t getCapasity()const { return capacity; }

		   bool operator==(const Vector& rhs)const;
		   bool operator!=(const Vector& rhs)const;

		   Vector& operator=(const Vector& rhs);
		   int& operator[](uint32_t index);
		   int& at(uint32_t index);
		   int& front();
		   int& back();

		   friend std::ostream& operator <<(std::ostream& os, const Vector& rhs);

		   Vector(const Vector& copy);

		   ~Vector();

	   private:

		   int32_t* Array;
		   uint32_t size;
		   uint32_t capacity;
	};

}

