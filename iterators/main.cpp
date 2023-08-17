#include "input_iterator.h"

int main() {
	my_vector<int> vec;
	for (int i = 0; i < 5; i++)
	{
		vec.push_back(i);
	}
	for (input_iterator<int> it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it << " ";
	}
}