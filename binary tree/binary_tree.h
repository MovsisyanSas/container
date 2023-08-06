#pragma once
#include<cmath>

template<typename T>
struct Node {
	T m_val;
	Node<T>* right;
	Node<T>* left;
	int r = 0;
	int l = 0;
	Node(const T& val) : right(nullptr), left(nullptr), m_val(val){}
};

template<typename T>
class bin_tree {
	Node<T>* root;
	double element;
public:
	bin_tree() : root(nullptr), element(0) {}
	bin_tree(const T& obj) { root = new Node<T>(obj); element = 1; }
public:
	void insert(const T& obj) {
		Node<T>* newNode = new Node<T>(obj);
		if (root == nullptr)
		{
			root = newNode;
		}
		else if (root->left == nullptr) { root->left = newNode; ++(root->l); }
		else if (root->right == nullptr) { root->right = newNode; ++(root->r); }
		else {
			Node<T>* temp = root;
			while (temp->right != nullptr && temp->left != nullptr) {
				if (temp->r >= temp->l)
				{
					++(temp->l);
					temp = temp->left;
				}
				else
				{
					++(temp->r);
					temp = temp->right;
				}
			}
			if (temp->left == nullptr)
			{
				temp->left = newNode;
			}
			else
			{
				temp->right = newNode;
			}
		}
		update_elemenet();
	}
	void update_elemenet() {
		element = 1 + root->l + root->r;
	}
	int levels() {
		return std::log2(element);
	}
	int leaves() {
		return (element + 1) / 2;
	}
	void display() {
		for (int i = 1; i <= levels(); i++)
		{
			traversal(root, i);
		}
	}
private:
	void traversal(Node<T>* obj, int level) {
		if (obj == nullptr)
		{
			return;
		}
		else if (level == 1) {
			std::cout << obj->m_val << "->";
		}
		else {
			traversal(obj->left, level - 1);
			traversal(obj->right, level - 1);
		}
	}
};
