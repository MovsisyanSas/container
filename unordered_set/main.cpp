#include "hash_table.h"

int main() {
	hash_table ht(10);
	for (int i = 0; i < 30; i++)
	{
		ht.insert(i);
	}
	ht.print();
}