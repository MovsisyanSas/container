#include <iostream>
#include "binary_tree.h"

int main() {
	bin_tree<int> tree;
	for (int i = 0; i < 8; i++)
	{
		tree.insert(i);
	}
	std::cout << tree.levels() << std::endl;
	tree.display();
}