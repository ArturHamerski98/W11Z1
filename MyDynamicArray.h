#pragma once
#include <exception>
struct InvalidArrayIndexException : public std::exception
{
	const char* what() const throw ()
	{
		return "Index out of size";
	}
};
class MyDynamicArray
{
public:
	int lastArrIndex;
	int arrSize;
	int myArry[10];
	int operator[](int index);
	void clear();
	MyDynamicArray* nextArr;
	void push_back(int item);
	int get(int index);
	void set(int index, int value);
	MyDynamicArray();
	MyDynamicArray(int arrSize, int lastArrIndex);

	void resize();

};

