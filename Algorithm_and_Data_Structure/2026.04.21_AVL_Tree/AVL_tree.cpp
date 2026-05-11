#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    int height;

    Node()
    {
        key = 0;
        left = nullptr;
        right = nullptr;
        height = 1;
    }

    Node(int k)
    {
        key = k;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

class AVLTree
{
private:
    Node *root;

    int height(Node *node)
    {
        if (node == nullptr)
            return 0;

        return node->height;
    }

    int getBalance(Node *node)
    {
        if (node == nullptr)
            return 0;
        return height(node->left) - height(node->right);
    }

    int max(int a, int b)
    {
        return (a >= b) ? a : b;
    }

    Node *rightRotate(Node *y)
    {
        Node *leftY = y->left;
        y->left = leftY->right;
        leftY->right = y;

        y->height = max(height(y->left), height(y->right)) + 1;
        leftY->height = max(height(leftY->left), height(leftY->right)) + 1;
        return leftY;
    }

    Node *leftRotate(Node *y)
    {
        Node *rightY = y->right;
        y->right = rightY->left;
        rightY->left = y;

        y->height = max(height(y->left), height(y->right)) + 1;
        rightY->height = max(height(rightY->left), height(rightY->right)) + 1;

        return rightY;
    }

    Node *insert(Node *root, int key)
    {
        if (root == nullptr)
        {
            Node *newNode = new Node(key);
            return newNode;
        }

        if (key < root->key)
        {
            root->left = insert(root->left, key);
        }
        else if (key > root->key)
        {
            root->right = insert(root->right, key);
        }
        else
        {
            return root;
        }

        root->height = max(height(root->left), height(root->right)) + 1;

        int balance = getBalance(root);

        if (balance > 1)
        {
            // LL rotate
            if (key < root->left->key)
            {
                root = rightRotate(root);
            }
            // LR rotate
            else if (key > root->left->key)
            {
                root->left = leftRotate(root->left);
                root = rightRotate(root);
            }
        }
        else if (balance < -1)
        {
            // RR rotate
            if (key > root->right->key)
            {
                root = leftRotate(root);
            }
            // RL rotate
            else if (key < root->right->key)
            {
                root->right = rightRotate(root->right);
                root = leftRotate(root);
            }
        }

        return root;
    }

    Node *deleteNode(Node *root, int key)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        if (key < root->key)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->key)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            if (root->left == nullptr && root->right == nullptr)
            {
                delete root;
                root = nullptr;
            }
            else if (root->left == nullptr)
            {
                Node *temp = root->right;
                delete root;
                root = temp;
            }
            else if (root->right == nullptr)
            {
                Node *temp = root->left;
                delete root;
                root = temp;
            }
            else
            {
                Node *successor = root->right;
                while (successor->left != nullptr)
                {
                    successor = successor->left;
                }

                root->key = successor->key;

                root->right = deleteNode(root->right, successor->key);
            }
        }

        if (root == nullptr)
        {
            return nullptr;
        }

        root->height = max(height(root->left), height(root->right)) + 1;

        int balance = getBalance(root);

        if (balance > 1)
        {
            if (getBalance(root->left) >= 0)
            {
                return rightRotate(root);
            }
            else
            {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
        }
        else if (balance < -1)
        {
            if (getBalance(root->right) <= 0)
            {
                return leftRotate(root);
            }
            else
            {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
        }

        return root;
    }

    void inorder(Node *root)
    {
        if (root == nullptr)
            return;

        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }

    void preorder(Node *root)
    {
        if (root == nullptr)
            return;

        cout << root->key;
        preorder(root->left);
        preorder(root->right);
    }

    bool isAVL(Node *root)
    {
        if (root == nullptr)
            return true;

        int balance = getBalance(root);
        if (balance > 1 || balance < -1)
        {
            return false;
        }
        return isAVL(root->left) && isAVL(root->right);
    }

public:
    AVLTree()
    {
        root = nullptr;
    }

    void insert(int key)
    {
        root = insert(root, key);
    }

    void inorder()
    {
        inorder(root);
    }

    void preorder()
    {
        preorder(root);
    }

    bool isAVL()
    {
        return isAVL(root);
    }

    void deleteKey(int key)
    {
        root = deleteNode(root, key);
    }
};

int main()
{
    AVLTree tree;

    tree.insert(50);
    tree.insert(40);
    tree.insert(30); // LL
    tree.insert(45);
    tree.insert(47); // LR

    cout << "Inorder print: ";
    tree.inorder();
    cout << endl;

    cout << "IS AVL? : " << (tree.isAVL() ? "TRUE" : "FALSE") << endl;

    return 0;
}
