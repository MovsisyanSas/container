#include <iostream>
#include "stack.h"

int main() {
	v_stack<int> st1;
	for (int i = 0; i < 5; i++)
	{
		st1.push(i);
	}
	for (int i = 0; i < 5; i++)
	{
		std::cout << st1.top() << std::endl;
		st1.pop();
	}

	std::cout << std::endl;
	std::cout << std::endl;

	l_stack<int> st2;
	for (int i = 5; i < 10; i++)
	{
		st2.push(i);
	}
	for (int i = 5; i < 10; i++)
	{
		std::cout << st2.top() << std::endl;
		st2.pop();
	}
}