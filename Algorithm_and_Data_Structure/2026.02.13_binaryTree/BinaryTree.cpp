#include <iostream>

using namespace std;

class Node {
public:
	int val;
	Node* left;
	Node* right;
	
	Node() : val(0), left(nullptr), right(nullptr) {}
	
	Node(int value) : val(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
	Node* root;
	
	void inorderTraversal(Node* root) {
		if (root == nullptr) return;
		
		inorderTraversal(root->left);
		cout << root->val << " ";
		inorderTraversal(root->right);
	}
	
	Node* insertNode(Node* node, int value) {
		if (node == nullptr) return new Node(value);
		
		if (value > node->val) {
			node->right = insertNode(node->right, value);
		} else if (value < root->val) {
			node->left = insertNode(node->left, value);
		}
		return node;
	}
	
public:
	BinaryTree() : root(nullptr) {}
	
	void displayInOrder() {
		inorderTraversal(root);
		cout << endl;
	}
	
	void insert(int value) {
		root = insertNode(root, value);
	}
};

int main() {
	BinaryTree tree;
	
	tree.insert(10);
	tree.insert(30);
	tree.insert(50);
	tree.insert(5);
	
	tree.displayInOrder();
	
	return 0;
}
