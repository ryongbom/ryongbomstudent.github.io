#include <iostream>

using namespace std;

struct treeNode
{
    int key;
    treeNode *left;
    treeNode *right;

    treeNode(int value) : key(value), left(NULL), right(NULL) {}

    ~treeNode() {}
};

class BinaryTree
{
private:
    treeNode *root;

    treeNode *insertNode(treeNode *root, int k)
    {
        if (root == NULL)
        {
            treeNode *newNode = new treeNode(k);
            return newNode;
        }

        if (k < root->key)
        {
            root->left = insertNode(root->left, k);
        }
        else
        {
            root->right = insertNode(root->right, k);
        }
        return root;
    }

    treeNode *deleteNode(treeNode *root, int k)
    {
        if (root == NULL)
            return NULL;

        if (k < root->key)
        {
            root->left = deleteNode(root->left, k);
        }
        else if (k > root->key)
        {
            root->right = deleteNode(root->right, k);
        }
        else
        {
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }
            else if (root->left == NULL && root->right != NULL)
            {
                treeNode *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->left != NULL && root->right == NULL)
            {
                treeNode *temp = root->left;
                delete root;
                return temp;
            }
            else
            {
                treeNode *current = root->right;
                while (current->left != NULL) // Why current->left? I thought current != NULL
                {
                    current = current->left;
                }
                root->key = current->key;
                root->right = deleteNode(root->right, current->key);
            }
        }
        return root;
    }

    void inorderTraversal(treeNode *root)
    {
        if (root == NULL)
            return;

        inorderTraversal(root->left);
        cout << root->key << " ";
        inorderTraversal(root->right);
    }

    void clear(treeNode *root)
    {
        if (root == NULL)
            return;

        clear(root->left);
        clear(root->right);
        delete root;
    }

public:
    BinaryTree() : root(NULL) {}
    BinaryTree(treeNode *node) : root(node) {}
    ~BinaryTree()
    {
        clear(root);
    }

    void insert(int value)
    {
        root = insertNode(root, value);
    }

    void deleteN(int value)
    {
        root = deleteNode(root, value);
    }

    void printInorder()
    {
        inorderTraversal(root);
        cout << endl;
    }
};

int main()
{
    BinaryTree tree;

    tree.insert(10);
    tree.insert(30);
    tree.insert(5);

    tree.printInorder();

    tree.deleteN(10);
    tree.printInorder();

    return 0;
}
