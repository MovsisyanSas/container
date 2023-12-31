#include "my_vector.h"
#include <iostream>

int main() {
	try {
		my_vector<int> vector(5);
		vector.push_back(1);
		vector.print();
		for (int i = 2; i <= 5; i++)
		{
			vector.push_back(i);
		}
		vector.print();
		vector.pop_back();
		vector.print();
		vector.erase(3);
		vector.print();
		std::cout << vector.size() << std::endl;
		std::cout << vector.at(-5);
	}
	catch (const char* s)
	{
		std::cout << s << std::endl;
	}
	catch (const std::exception& err) {
		std::cout << err.what() << std::endl;
	}
}