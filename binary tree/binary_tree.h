#pragma once
#include <cmath>
#include <stack>
#include <queue>

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
		return std::log2(element + 1);
	}
	int leaves() {
		return (element + 1) / 2;
	}
	void display(std::string order) {
		if (order == "inorder")
		{
			inorder_traversal(root);
			std::cout << std::endl;
		}
		else if (order == "preorder")
		{
			preorder_traversal(root);
			std::cout << std::endl;
		}
		else if (order == "postorder")
		{
			postorder_traversal(root);
			std::cout << std::endl;
		}
	}
private:
	void inorder_traversal(Node<T>* nd) {
		if (nd == nullptr)
		{
			return;
		}
		inorder_traversal(nd->left);
		std::cout << nd->m_val << ' ';
		inorder_traversal(nd->right);
	}
	void preorder_traversal(Node<T>* nd) {
		if (nd == nullptr)
		{
			return;
		}
		std::cout << nd->m_val << ' ';
		preorder_traversal(nd->left);
		preorder_traversal(nd->right);
	}
	void postorder_traversal(Node<T>* nd) {
		if (nd == nullptr)
		{
			return;
		}
		inorder_traversal(nd->left);
		inorder_traversal(nd->right);
		std::cout << nd->m_val << ' ';
	}
};
