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
	list.push_front(-1);
	list.print();
	list.pop_front();
	list.print();
	std::cout << "front: " << list.front() << std::endl;
	std::cout << "back: " << list.back() << std::endl;
	std::cout << "2nd from the end: " << list.n_th_from_end(2) << std::endl;
	list.reverseList();
	list.print();
	list.makeCycle(2);
	list.print();
	std::cout << list.hasCycle() << std::endl;
	list.clean();
	std::cout << "after cleaning: " << std::endl;
	list.print();
}