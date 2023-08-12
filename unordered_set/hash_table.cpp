#include "hash_table.h"


hash_table :: hash_table(int S) {
	vec = my_vector<List<int>>(S);
	for (int i = 0; i < S; i++) {
		vec.push_back(List<int>());
	}
}


void hash_table::insert(int obj) {
	int s = obj % vec.size();
	vec[s].push_back(obj);
}
void hash_table::print() {
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << (i + 1) << ") ";
		vec[i].print();
		std::cout << std::endl;
	}
}

