#include <iostream>
using namespace std;

void swap_ref(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
int find_max(int arr[], int size) {
	//Â­ºã¼¬ËÍ ÊïË±½å¶® 
	if (size <= 0) {
		cerr << "Error!: Empty array!" << endl;
		return INT_MIN;
	} 
	int max_val = arr[0];
	for (int i = 0; i < size; i++) {
		if (arr[i] > max_val)
			max_val = arr[i];
	}
	return max_val;
}
int my_strlen(const char* str) {
	//NULL¾Ë¿Í Â­ºã°á¼³
	if (str == '\0') {
		cerr << "Error!: Null pointer passed to my_strlen!" << endl;
		return -1;
	} 
	int length = 0;
	while(str[length] != '\0') {
		length++;
	}
	return length;
}
int factorial(int n) {
	if (n <= 1) {
		return 1;
	}
	return n * factorial(n - 1);
}

int main() {
    cout << "=== swap_ref test ===" << endl;
    int x = 5, y = 10;
    cout << "Before: x=" << x << ", y=" << y << endl;
    swap_ref(x, y);
    cout << "After: x=" << x << ", y=" << y << endl;
    
    cout << "\n=== find_max test ===" << endl;
    int arr[] = {3, 7, 2, 9, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Max: " << find_max(arr, size) << endl;
    
    cout << "\n=== my_strlen test ===" << endl;
    char str[] = "Hello, Russia!";
    cout << "str[]: " << str << endl;
    cout << "length: " << my_strlen(str) << endl;
    
    cout << "\n=== factorial test ===" << endl;
    cout << "5! = " << factorial(5) << endl;
    cout << "1! = " << factorial(1) << endl;
    cout << "0! = " << factorial(0) << endl;
    
    return 0;
}
