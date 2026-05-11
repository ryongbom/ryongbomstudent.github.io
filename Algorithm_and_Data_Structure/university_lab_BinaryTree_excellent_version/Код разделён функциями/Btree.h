#ifndef BTREE_H
#define BTREE_H

#include "Data.h"

struct Btree
{
    Data data;
    Btree *left;
    Btree *right;

    Btree(const Data &d);
};

// tree operation function
Btree *insertNode(Btree *root, const Data &data);
Btree *deleteNode(Btree *root, const string &code);
Btree *searchNode(Btree *root, const string &code);
void deleteTree(Btree *root);

// functions for traversal
void inorderTraversal(Btree *root);
void inorderDescending(Btree *root);
void preorderTraversal(Btree *root);
void postorderTraversal(Btree *root);
void breadthFirstTraversal(Btree *root);

// it is my task function
int countAboveAveragePrice(Btree *root);

// utility functions
void calculateSumAndCount(Btree *root, double &sum, int &count);
double calculateAverage(Btree *root);
void countAboveHelper(Btree *root, double average, int &count);

#endif