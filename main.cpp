#include "MyDynamicArray.h"
#include <iostream>


int main() {
   
	MyDynamicArray tab;

	for (int i = 0; i < 33; i++){
		tab.push_back(i);

	}
	tab.set(3, 55);
	tab.set(21, 2245);
	std::cout << tab[11] << std::endl;
	std::cout << tab[8] << std::endl;

	//tab.set(43,44);
	//std::cout << tab.get(77);
	//tab.clear();
	//tab.push_back(11);
	return 0;
}