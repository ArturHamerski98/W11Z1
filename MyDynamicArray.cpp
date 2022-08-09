#include "MyDynamicArray.h"
#include "InvalidArrayIndexException.h"
#include <iostream>

int MyDynamicArray::operator[](int index)
{
		return get(index);
}
void MyDynamicArray::clear()
{
	this->lastArrIndex = -1;
	this->arrSize = 10;
	this->nextArr = nullptr;
	for (int i = 0; i < 10; i++) {
		myArry[i] = 0;
	}
	delete nextArr;
}
void MyDynamicArray::push_back(int item)
{
	
		
	if (lastArrIndex >= arrSize)
	{

		
		lastArrIndex++;
		if (nextArr == nullptr)
		{
			lastArrIndex--;
			resize();
		}
			
		nextArr->push_back(item);

	}
	else
	{
		lastArrIndex++;
		this->myArry[lastArrIndex % 10] = item;
	}
		
	
}

int MyDynamicArray::get(int index)
{
	if (index > lastArrIndex+1)
	{
		try {
			throw InvalidArrayIndexException();
		}
		catch (InvalidArrayIndexException& e)
		{
			std::cout << e.what() << std::endl;
			return -1;
		}
		

	}
		

	if (index >= arrSize)
	{
		
		nextArr->get(index);

	}
	else
	{

		return this->myArry[index % 10];
	}
}

void MyDynamicArray::set(int index, int value)
{
	if (index > lastArrIndex + 1)
	{
		try {
			throw InvalidArrayIndexException();
		}
		catch (InvalidArrayIndexException& e)
		{
			std::cout << e.what() << std::endl;
			return;
		}
		
		
	}
		
	
	if (index >= arrSize)
	{

		nextArr->set(index, value);

	}
	else
	{
		this->myArry[index%10] = value;
	}
}

MyDynamicArray::MyDynamicArray()
{
	lastArrIndex = -1;
	arrSize = 9;
	nextArr = nullptr;
}

MyDynamicArray::MyDynamicArray(int arrSize, int lastArrIndex)
{
	this->lastArrIndex = lastArrIndex;
	this->arrSize = arrSize;
	nextArr = nullptr;
	

}


void MyDynamicArray::resize()
{
	nextArr = new MyDynamicArray(arrSize+10,lastArrIndex);
}
