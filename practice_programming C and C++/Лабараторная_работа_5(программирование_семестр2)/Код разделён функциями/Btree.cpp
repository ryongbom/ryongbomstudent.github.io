#include "Btree.h"
#include <iostream>
#include <queue>
using namespace std;

Btree::Btree(const Data &d) : data(d), left(nullptr), right(nullptr) {}

// tree operation function
Btree *insertNode(Btree *root, const Data &data)
{
	if (root == nullptr)
	{
		return new Btree(data);
	}

	if (data.code < root->data.code)
	{
		root->left = insertNode(root->left, data);
	}
	else if (data.code > root->data.code)
	{
		root->right = insertNode(root->right, data);
	}
	return root;
}

Btree *deleteNode(Btree *root, const string &code)
{
	if (root == nullptr)
		return root;

	if (code < root->data.code)
	{
		root->left = deleteNode(root->left, code);
	}
	else if (code > root->data.code)
	{
		root->right = deleteNode(root->right, code);
	}
	else
	{
		// case1: no leaf node
		if (root->left == nullptr && root->right == nullptr)
		{
			delete root;
			return nullptr;
		}

		// case2: have only left node
		else if (root->left != nullptr && root->right == nullptr)
		{
			Btree *temp = root->left;
			delete root;
			return temp;
		}

		// case3: have only right node
		else if (root->left == nullptr && root->right != nullptr)
		{
			Btree *temp = root->right;
			delete root;
			return temp;
		}

		// case4: have only left, right nodes
		else
		{
			Btree *temp = root->right;
			while (temp->left != nullptr)
			{
				temp = temp->left;
			}

			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data.code);
		}
	}
	return root;
}

Btree *searchNode(Btree *root, const string &code)
{
	if (root == nullptr || root->data.code == code)
	{
		return root;
	}
	if (code < root->data.code)
	{
		return searchNode(root->left, code);
	}
	return searchNode(root->right, code);
}

void deleteTree(Btree *root)
{
	if (root == nullptr)
		return;

	deleteTree(root->left);
	deleteTree(root->right);
	delete root;
}

// functions for traversal
void inorderTraversal(Btree *root)
{
	if (root == nullptr)
		return;

	inorderTraversal(root->left);
	root->data.display();
	inorderTraversal(root->right);
}

void inorderDescending(Btree *root)
{
	if (root == nullptr)
		return;
	inorderDescending(root->right);
	root->data.display();
	inorderDescending(root->left);
}

void preorderTraversal(Btree *root)
{
	if (root == nullptr)
		return;
	root->data.display();
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

void postorderTraversal(Btree *root)
{
	if (root == nullptr)
		return;
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	root->data.display();
}

void breadthFirstTraversal(Btree *root)
{
	if (root == nullptr)
	{
		cout << "Tree is empty." << endl;
		return;
	}

	queue<Btree *> q;
	q.push(root);

	cout << "=== Breadth-First Traversal ===" << endl;
	while (!q.empty())
	{
		Btree *current = q.front();
		q.pop();

		current->data.display();

		if (current->left != nullptr)
			q.push(current->left);
		if (current->right != nullptr)
			q.push(current->right);
	}
}

// utility functions
void calculateSumAndCount(Btree *root, double &sum, int &count)
{
	if (root == nullptr)
		return;

	sum += root->data.price;
	count++;
	calculateSumAndCount(root->left, sum, count);
	calculateSumAndCount(root->right, sum, count);
}

double calculateAverage(Btree *root)
{
	if (root == nullptr)
		return 0;

	double sum = 0.0;
	int count = 0;
	calculateSumAndCount(root, sum, count);

	return (count > 0) ? sum / count : 0;
}

void countAboveHelper(Btree *root, double average, int &count)
{
	if (root == nullptr)
		return;

	if (root->data.price > average)
	{
		count++;
		root->data.display();
	}

	countAboveHelper(root->left, average, count);
	countAboveHelper(root->right, average, count);
}

// it is my task function
int countAboveAveragePrice(Btree *root)
{
	if (root == nullptr)
		return 0;

	double average = calculateAverage(root);
	int count = 0;

	cout << fixed << setprecision(2);
	cout << endl;
	cout << "=== Price Analysis ===" << endl;
	cout << "Average price: $" << average << endl;
	cout << endl;
	cout << "=== Parts above average price ===" << endl;

	countAboveHelper(root, average, count);

	return count;
}