#include <iostream>
#include <vector>
#include <list>
#include <set>

void print(std::set<int> s) {
	for (auto in : s) {
		std::cout << in << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

void print(std::vector<int> vec) {
	for (auto in : vec) {
		std::cout << in << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

void print(std::list<int> l) {
	for (auto in : l) {
		std::cout << in << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

void delete_less_than(std::vector<int>& vec, int n) {
	for (auto it = vec.begin(); it != vec.end();)
	{
		if (*it < n)
		{
			it = vec.erase(it);
		}
		else
		{
			++it;
		}
	}
}

void delete_less_than(std::list<int>& l, int n) {
	for (auto it = l.begin(); it != l.end();)
	{
		if (*it < n)
		{
			it = l.erase(it);
		}
		else
		{
			++it;
		}
	}
}

void delete_less_than(std::set<int>& s, int n) {
	for (auto it = s.begin(); it != s.end();)
	{
		if (*it < n)
		{
			it = s.erase(it);
		}
		else
		{
			++it;
		}
	}
}

int main() {

	std::vector<int> vec = {1, 15, 3, 6, 87, 100, 54, 26, 14, 78};
	std::list<int> l = {1, 15, 3, 6, 87, 100, 54, 26, 14, 78};
	std::set<int> s = {1, 15, 3, 6, 87, 100, 54, 26, 14, 78};

	delete_less_than(vec, 50);
	print(vec);

	delete_less_than(l, 50);
	print(l);

	delete_less_than(s, 50);
	print(s);
}