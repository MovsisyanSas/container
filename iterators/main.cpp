#include "vector.h"

int main() {
	my_vector<int> vec;
	for (int i = 0; i < 5; i++)
	{
		vec.push_back(i);
	}
	for (my_vector<int>::Iterator it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it << " ";
	}
}