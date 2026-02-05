#include <iostream>
using namespace std;

template <typename T>

class Node {
private:
	T data;
	Node<T>* next;
public:
	Node(T value) : data(value), next(nullptr) {
		cout << "create node" << data << endl;
	}	
	
	~Node() {
		cout << "delete node" << data << endl;
	}
	
	T getData() const {
		return data;
	}
	
	void setData(T value) {
		data = value;
	}
	
	Node<T>* getNext() const {
		return next;
	}
	
	void setNext(Node<T>* nextNode) {
		next = nextNode;
	}
	
	void print() const {
		cout << "[" << data << "]";
	}
};

template <typename T>
class LinkedList {
private:
	Node<T>* head;
	int size;
public:
	LinkedList() : head(nullptr), size(0) {
		cout << endl;
		cout << "create linked list" << endl;
	}
	
	~LinkedList() {
		clear();
		cout << "delete linked list" << endl;
	}
	
	bool isEmpty() const {
		return head == nullptr;
	}
	
	int getSize() const {
		return size;
	}
	
	void clear() {
		Node<T>* current = head;
		while (current != nullptr) {
			Node<T>* next = current->getNext();
			delete current;
			current = next;
		}
		head = nullptr;
		size = 0;
		cout << "clear list" << endl;
	}
	
	void print() const {
		if (isEmpty()) {
			cout << "empty list" << endl;
			return;
		}
		Node<T>* current = head;
		cout << "List: ";
		while (current != nullptr) {
			current->print();
			cout << " -> ";
			current = current->getNext();
		}
		cout << "NULL (size: " << size << ")" << endl;
	}
	
	void pushFront(T value) {
		Node<T>* newNode = new Node<T>(value);
		newNode->setNext(head);
		head = newNode;
		size++;
		cout << "add node in front of list: " << value << endl; 
	}
	
	void pushBack(T value) {
		Node<T>* newNode = new Node<T>(value);
		
		if (isEmpty()) {
			head = newNode;
		} else {
			Node<T>* current = head;
			
			while (current->getNext() != nullptr) {
				current = current->getNext();
			}
			current->setNext(newNode);
		}
		size++;
		cout << "add node back: " << value << endl;
	}
	
	bool insertAt(T value, int position) {
		if (position < 0 || position > size) {
			cout << "position error: " << position << endl;
			return false;
		}
		
		if (position == 0) {
			pushFront(value);
			return true;
		}
		
		Node<T>* newNode = new Node<T>(value);
		Node<T>* current = head;
		
		for (int i = 0; i < position - 1; i++) {
			current = current->getNext();
		}
		
		newNode->setNext(current->getNext());
		current->setNext(newNode);
		size++;
		
		cout << "in position " << position << " add node: " << value << endl;
		return true;
	}
};

int main() {
	cout << "=== C++ linkedList test started! ===" << endl;
	
	LinkedList<int> myList;
	
	cout << endl;
	cout << "1. current status:" << endl;
	myList.print();
	cout << "Is empty? ";
	if (myList.isEmpty()) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	
	cout << endl;
	cout << "2. test adding node:" << endl;
	myList.pushBack(10);
	myList.pushBack(20);
	myList.pushFront(5);
	myList.insertAt(15, 2);
	myList.print();
	
	cout << endl;
	cout << "3. position false:" << endl;
	myList.insertAt(99, 10);
	
	cout << endl;
	cout << "4. add more nodes:" << endl;
	myList.pushBack(25);
	myList.pushBack(30);
	myList.print();
	
	cout << endl;
	cout << "5. clear list:" << endl;
	myList.clear();
	myList.print();
	
	return 0;
}
	