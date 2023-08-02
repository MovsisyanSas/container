#include "queue.h"
#include <iostream>

int main() {
	queue<int> Q;
	for (int i = 0; i < 9; i++)
	{
		Q.push(i);
	}
	for (int i = 0; i < 5; i++)
	{
		std::cout << Q.top() << std::endl;
		Q.pop();
	}
	Q.push(-1);
	for (int i = 0; i < 5; i++)
	{
		std::cout << Q.down() << std::endl;
		Q.down();
	}
	std::cout << "printing -1 cause pop() isn't touching down of queue until last element" << std::endl;
}