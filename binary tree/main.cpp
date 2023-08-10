#include <iostream>
#include "binary_tree.h"

int main() {
	bin_tree<int> tree;
	for (int i = 0; i < 7; i++)
	{
		tree.insert(i);
	}
	/*
			 0
		   /   \
		  1     2
		 / \   / \  
		3	5 4   6
	 
	*/
	std::cout << tree.levels() << std::endl;
	tree.display("inorder");
	tree.display("preorder");
	tree.display("postorder");
	tree.display("level");
}