#include <iostream>

using namespace std;

struct node
{
    int key;
    node *ptr;

    node(int value) : key(value), ptr(NULL) {}

    ~node() {}
};

class linkedList
{
private:
    node *head;
    int size;

public:
    linkedList() : head(NULL), size(0) {}

    ~linkedList()
    {
        clear();
    }

    void clear()
    {
        node *current = head;
        while (current != NULL)
        {
            node *temp = current->ptr;
            delete current;
            current = temp;
        }
        head = NULL;
        size = 0;
    }

    void append(int a)
    {
        node *newNode = new node(a);
        node *temp = head;
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            while (temp->ptr != NULL)
            {
                temp = temp->ptr;
            }
            temp->ptr = newNode;
        }
        size++;
    }

    void prepend(int a)
    {
        node *newNode = new node(a);
        node *temp = head;

        newNode->ptr = temp;
        head = newNode;
        size++;
    }

    void deleteNode(int position)
    {
        if (head == NULL || position > size || position < 1)
        {
            return;
        }
        node *temp = head;
        if (position == 1)
        {
            head = head->ptr;
            delete temp;
            size--;
            return;
        }
        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->ptr;
        }
        node *toDelete = temp->ptr;
        temp->ptr = toDelete->ptr;
        delete toDelete;
        size--;
    }

    int search(int a)
    {
        if (head == NULL)
            return -1;
        int pos = 1;
        node *current = head;
        while (current != NULL)
        {
            if (current->key == a)
            {
                return pos;
            }
            current = current->ptr;
            pos++;
        }
        return -1;
    }

    void printList()
    {
        if (head == NULL)
        {
            cout << "List is empty! " << endl;
            return;
        }
        cout << "List: ";
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->key;
            cout << "->";
            temp = temp->ptr;
        }
        cout << "NULL" << endl;
    }

    int getSize()
    {
        return size;
    }
};

int main()
{
    linkedList root;

    cout << "=== test with linked list ===" << endl;
    cout << "1. add element in back of list: 10, 20, 50, 100" << endl;
    root.append(10);
    root.append(20);
    root.append(50);
    root.append(100);
    root.printList();

    cout << "2. add element in front of list: 30, 40" << endl;
    root.prepend(30);
    root.prepend(40);
    root.printList();

    cout << "3. delete element in position 2:" << endl;
    root.deleteNode(2);
    root.printList();

    cout << "4. Search element, so couting position of element: 10" << endl;
    int searchPos = root.search(10);
    cout << "Position of element: " << searchPos << endl;
    cin.ignore();

    return 0;
}
