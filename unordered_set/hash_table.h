#pragma once
#include "vector.h"
#include "list.h"
#include <iostream>

class hash_table {
	my_vector<List<int>> vec;
public:
	hash_table() = delete;
	hash_table(int S);
public:
	void insert(int obj);
	void print();
};