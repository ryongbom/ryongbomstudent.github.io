#include <iostream>
#include <string>
using namespace std;

struct PriorityQueue
{
    int heap[100000];
    int size;

    PriorityQueue()
    {
        size = 0;
    }

    void siftUp(int i)
    {
        if (i == 1)
            return;
        while (i > 1 && heap[i] > heap[i / 2])
        {
            swap(heap[i], heap[i / 2]);
            i = i / 2;
        }
    }

    void insert(int value)
    {
        size++;
        heap[size] = value;

        siftUp(size);
    }

    void siftDown(int i)
    {
        while (2 * i <= size)
        {
            int child = i * 2;
            if (child + 1 <= size && heap[child + 1] > heap[child])
            {
                child++;
            }

            if (heap[i] >= heap[child])
            {
                break;
            }

            swap(heap[i], heap[child]);
            i = child;
        }
    }

    int extractMax()
    {
        int maxValue = heap[1];
        heap[1] = heap[size];
        size--;
        siftDown(1);
        return maxValue;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void printHeap()
    {
        cout << "Heap: ";
        for (int i = 1; i <= size; i++)
        {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    PriorityQueue pq;
    int n;
    string command;

    cout << "Enter number of operations: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> command;

        if (command == "Insert")
        {
            int value;
            cin >> value;
            pq.insert(value);
            cout << "Inserted " << value << endl;
            pq.printHeap();
        }
        else if (command == "ExtractMax")
        {
            if (!pq.isEmpty())
            {
                int maxVal = pq.extractMax();
                cout << "Extracted Max: " << maxVal << endl;
                pq.printHeap();
            }
            else
            {
                cout << "Heap is empty!" << endl;
            }
        }
    }

    return 0;
}
