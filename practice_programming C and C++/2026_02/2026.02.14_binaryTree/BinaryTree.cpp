#include <iostream>
#include <queue>
#include <stack>
#include <algoritm>

using namespace std;

class TreeNode {
	int val;
	TreeNode* left;
	TreeNdoe* right;
	
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} 
};

class BinaryTree {
	TreeNode* root;
	
	void preorderHelper(TreeNode* node) {
		if (root == nullptr) return;
		
		cout << node->val << " ";
		preorderHelper(node->left);
		preorderHelper(node->right);
	}
	
	void inorderHelper(TreeNode* node) {
		if (root == nullptr) return;
		
		inorderHelper(node->left);
		cout << node->val << " ";
		inorderHelper(node->right);
	}
	
	void postorderHelper(TreeNode* node) {
		if (root == nullptr) return;
		
		postorderHelper(node->left);
		postorderHelper(node->right);
		cout << node->val << " ";
	}
	
	int getHightHelper(TreeNode* node) {
		
	}
};