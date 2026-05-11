#include <iostream>
using namespace std;

template <typename T>

class CircularNode {
private:
	T data;
	CircularNode<T>* next;
public:
	CircularNode(T value) : data(value), next(this) { // this is important
		cout << "CircularNode created: " << data << endl;
	}
	
	~CircularNode() {
		cout << "CircularNode deleted: " << data << endl;
	}
	
	T getData() const {
		return data;
	}
	
	void setNext(CircularNode<T>* newNext) {
		next = newNext;
	}
	
	CircularNode<T>* getNext() const {
		return next;
	}
	
	void print() const {
		cout << "[" << data << "]";
	}
};

template <typename T>

class CircularLinkedList {
private:
	int size;
	CircularNode<T>* tail;
public:
	CircularLinkedList() : tail(nullptr), size(0) {
		cout << "circular Linked List created" << endl;
	}
	
	~CircularLinkedList() {
		cout << "circular Linked List deleted" << endl;
	}
	
	bool isEmpty() const {
		return tail == nullptr;
	}
	
	int getSize() const {
		return size;
	}
	
	CircularNode<T>* getHead() const {
		if (isEmpty()) return nullptr;
		return tail->getNext(); 
	}
	
	void print() const {
		if (isEmpty()) {
			cout << "list is empty!" << endl;
			return;
		}
		
		CircularNode<T>* current = getHead();
		cout << "Circular List: ";
		
		do {
			current->print();
			cout << " -> ";
			current = current->getNext();
		} while(current != getHead());
		
		cout << "(back to head)" << endl;
		cout << "Size: " << size << endl;
		cout << "Tail points to: " << tail->getData() << endl;
		cout << "Head is: " << getHead()->getData() << endl;
	}
	
	void addFront(T value) {
		CircularNode<T>* newNode = new CircularNode<T>(value);
		
		if (isEmpty()) {
			tail = newNode;
			newNode->setNext(newNode);
		} else {
			newNode->setNext(tail->getNext());
			tail->setNext(newNode);
		}	
		size++;
		cout << "added to front: " << value << endl;
	}
	
	void pushBack(T value) {
		CircularNode<T>* newNode = new CircularNode<T>(value);
		
		if (isEmpty()) {
			tail = newNode;
			newNode->setNext(newNode);
		} else {
			newNode->setNext(getHead());
			tail->setNext(newNode);
			tail = newNode;
		}
		size++;
		cout << "added to back: " << value << endl; 
	}
	
	bool insertAt(T value, int position) {
		if (position < 0 || position > size) {
			cout << "position error!" << endl;
			return false;
		}
		if (position == 0) {
			addFront(value);
			return true;
		}
		
		if (position == size) {
			pushBack(value);
			return true;
		}
		
		CircularNode<T>* current = getHead();
		for (int i = 0; i < position - 1; i++) {
			current = current->getNext();
		}
		
		CircularNode<T>* newNode = new CircularNode<T>(value);
		newNode->setNext(current->getNext());
		current->setNext(newNode);
		size++;
		
		cout << "Inserted at position " << position << " value: " << value << endl;
		return true;
	}
	
	void popFront() {
		if (isEmpty()) {
			cout << "Circular Linked List is empty!" << endl;
			return;
		}
		if (size == 1) {
			delete tail;
			tail = nullptr;
		} else {
			CircularNode<T>* head = getHead();
			tail->setNext(head->getNext());
			delete head;
		}
		size--;
		cout << "Romoved front node" << endl;
	}
	
	void popBack() {
		if (isEmpty()) {
			cout << "Circular Linked List is empty!" << endl;
			return;
		}
		if (size == 1) {
			delete tail;
			tail = nullptr;
		} else {
			CircularNode<T>* current = getHead();
			while (current->getNext() != tail) {
				current = current->getNext();
			}
			current->setNext(getHead());
			delete tail;
			tail = current;
		}
		size--;
		cout << "Removed back node" << endl;
	}
	
	// it is important function
	void clear() {
		if (isEmpty()) {
			cout << "Circular Linked list is empty!" << endl;
			return;
		}
		
		// break circle !important
		tail->setNext(nullptr);
		
		CircularNode<T>* current = getHead();
		
		while (current != nullptr) {
			CircularNode<T>* next = current->getNext();
			delete current;
			current = next;
		}
		tail = nullptr;
		size = 0;
		cout << "Circular list cleared" << endl;
	}
};

int main() {
    cout << "=== Circular Linked List Comprehensive Test ===" << endl;
    
    CircularLinkedList<int> list;
    
    // Test 1: Initial state
    cout << "\n--- Test 1: Initial State ---" << endl;
    cout << "Is empty? " << (list.isEmpty() ? "Yes" : "No") << endl;
    cout << "Size: " << list.getSize() << endl;
    list.print();
    
    // Test 2: Add to front
    cout << "\n--- Test 2: Add to Front ---" << endl;
    list.addFront(30);
    list.addFront(20);
    list.addFront(10);
    list.print();
    
    // Test 3: Add to back
    cout << "\n--- Test 3: Add to Back ---" << endl;
    list.pushBack(40);
    list.pushBack(50);
    list.print();
    
    // Test 4: Insert at specific positions
    cout << "\n--- Test 4: Insert at Positions ---" << endl;
    list.insertAt(25, 2);    // Insert 25 at position 2
    list.insertAt(45, 5);    // Insert 45 at position 5
    list.print();
    
    // Test 5: Test invalid position
    cout << "\n--- Test 5: Invalid Position Test ---" << endl;
    list.insertAt(99, 10);   // Should fail
    list.insertAt(99, -1);   // Should fail
    
    // Test 6: Remove from front
    cout << "\n--- Test 6: Remove from Front ---" << endl;
    list.popFront();
    list.print();
    
    // Test 7: Remove from back
    cout << "\n--- Test 7: Remove from Back ---" << endl;
    list.popBack();
    list.print();
    
    // Test 8: Multiple operations
    cout << "\n--- Test 8: Mixed Operations ---" << endl;
    list.addFront(5);
    list.pushBack(55);
    list.insertAt(35, 3);
    list.print();
    
    // Test 9: Clear the list
    cout << "\n--- Test 9: Clear List ---" << endl;
    list.clear();
    cout << "Is empty? " << (list.isEmpty() ? "Yes" : "No") << endl;
    list.print();
    
    // Test 10: Operations on empty list
    cout << "\n--- Test 10: Empty List Operations ---" << endl;
    list.popFront();    // Should show error
    list.popBack();     // Should show error
    list.print();
    
    // Test 11: Rebuild list
    cout << "\n--- Test 11: Rebuild List ---" << endl;
    for(int i = 1; i <= 5; i++) {
        list.pushBack(i * 10);
    }
    list.print();
    
    // Test 12: Check circular nature
    cout << "\n--- Test 12: Verify Circular Structure ---" << endl;
    if(list.getHead() != nullptr) {
        CircularNode<int>* current = list.getHead();
        cout << "Traversing 2 full cycles:" << endl;
        for(int i = 0; i < list.getSize() * 2; i++) {
            current->print();
            cout << " ";
            current = current->getNext();
        }
        cout << endl;
    }
    
    // Final state
    cout << "\n--- Final State ---" << endl;
    cout << "Size: " << list.getSize() << endl;
    cout << "Is empty? " << (list.isEmpty() ? "Yes" : "No") << endl;
    list.print();
    
    cout << "\n=== All Tests Completed ===" << endl;
    
    return 0;
}