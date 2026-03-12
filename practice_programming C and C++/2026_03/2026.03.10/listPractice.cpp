#include <iostream>

using namespace std;

struct Node
{
    int key;
    Node *ptr;

    Node(int k) : key(k), ptr(NULL) {}

    ~Node() {}
};

class linkedList
{
private:
    Node *headNode;
    int size;

public:
    linkedList() : headNode(NULL), size(0) {}

    ~linkedList()
    {
        clear();
    }

    void insertFront(int k)
    {
        Node *newNode = new Node(k);
        Node *temp = headNode;
        newNode->ptr = temp;
        headNode = newNode;
        size++;
    }

    void append(int k)
    {
        Node *newNode = new Node(k);
        Node *current = headNode;

        if (headNode == NULL)
        {
            headNode = newNode;
        }
        else
        {
            while (current->ptr != NULL)
            {
                current = current->ptr;
            }
            current->ptr = newNode;
        }
        size++;
    }

    void printNode()
    {
        Node *current = headNode;
        cout << "LinkedList: ";
        while (current != NULL)
        {
            cout << current->key;
            cout << "->";
            current = current->ptr;
        }
        cout << "NULL" << endl;
    }

    void clear()
    {
        if (headNode == NULL)
            return;

        Node *current = headNode;

        while (current != NULL)
        {
            Node *temp = current->ptr;
            delete current;
            current = temp;
        }
        headNode = NULL;
        size = 0;
    }
};

int main()
{
    linkedList lst;

    lst.insertFront(10);
    lst.insertFront(20);
    lst.insertFront(30);
    lst.append(5);
    lst.append(50);
    lst.append(60);

    lst.printNode();

    return 0;
}
