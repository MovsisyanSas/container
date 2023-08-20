#include <iostream>
#include "sort.h"

void fill(std::vector<int>& vec,int size) {
	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		vec.push_back(rand() % 10);
	}
}

void fill(std::list<int>& ls, int size) {
	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		ls.push_back(rand() % 10);
	}
}

void print(std::list<int>& list) {
	for (typename std::list<int>::iterator i = list.begin(); i != list.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;

}
void print(std::vector<int>& vec) {
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	std::vector<int> vec;
	fill(vec, 10);
	std::cout << "Before sort(vector): ";
	print(vec);

	sort::counting_sort(vec,10);
	std::cout << "After sort(vector): ";
	print(vec);
	
	std::list<int> ls;
	fill(ls, 10);
	std::cout << "Before sort(list): ";
	print(ls);

	sort::insertion_sort<int>(ls);
	std::cout << "After sort(list): ";
	print(ls);
}