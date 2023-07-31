#include <iostream>
#include "list.h"

int main() {
	List<int> list;
	for (int i = 0; i < 5; i++)
	{
		list.push_back(i);
	}
	list.print();
	list.pop_back();
	list.print();
	list.insert(3, 10);
	list.print();
	list.erase(3);
	list.print();
}