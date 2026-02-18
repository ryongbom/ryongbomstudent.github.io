#include <iostream>
#include <queue>
#include <stack>
#include <algoritm>

using namespace std;

class TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	
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
		if (node == nullptr) return 0;
		return max(getHightHelper(node->left), getHightHelper(node->right)) + 1;
	}

	int getSizeHelper(TreeNode* node) {
		if (node == nullptr) return 0;
		return getSizeHelper(node->left) + getSizeHelper(node->right) + 1;
	}

	int getLeafCountHelper(TreeNode* node) {
		if (node == nullptr) return 0;
		if (node->left == nullptr && node->right == nullptr) return 1;
		return getLeafCountHelper(node->left) + getLeafCountHelper(node->right);
	}
};