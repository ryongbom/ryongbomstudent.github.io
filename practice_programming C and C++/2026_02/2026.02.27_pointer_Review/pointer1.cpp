#include <iostream>
using namespace std;

int main() {
	int value = 42;
	int* ptr = &value;
	
    cout << "value: " << value << endl;
    cout << "value's adress': " << &value << endl;
    cout << "ptr: " << ptr << endl;
    cout << "ptr's pointing value': " << *ptr << endl;
    
    return 0;
}