#include <iostream>
using namespace std;

int main() {
	int value = 42;
	int* ptr = &value;
	int** pptr = &ptr;
	
    cout << "value: " << value << endl;
    cout << "value's adress': " << &value << endl;
    
    cout << "ptr: " << ptr << endl;
    cout << "ptr's adress: " << &ptr << endl;
    cout << "ptr's pointing value': " << *ptr << endl;
    
    cout << "pptr: " << pptr << endl;
    cout << "ptr's adress which pptr's pointing: " << *pptr << endl;
    cout << "Accessing value through pptr: " << **pptr << endl;
    
	**pptr = 100;
	cout << "changed value: " << value << endl;
	
	int newValue = 999;
	*pptr = &newValue;
	cout << "ptr's new pointing value: " << *ptr << endl;
	cout << "value: " << value << endl; 
    
    return 0;
}