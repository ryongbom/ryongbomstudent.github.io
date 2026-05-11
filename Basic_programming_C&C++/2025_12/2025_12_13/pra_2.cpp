#include <iostream>
using namespace std;

int main() {
	int x = 10, y = 3;
	double result1, result2, result3;
	
	result1 = x / y;
	result2 = (double)x / y;
	result3 = x / (double)y;
		
	int a = 5;
	int b = a++;
	int c = ++a;
	
	bool condition1 = (x > 5) && (y < 5);
	bool condition2 = (x == 10) || (y == 10);
	
	cout << "=== Guess result ===" << endl;
	cout << "result1 = " << result1 << endl;
	cout << "result2 = " << result2 << endl;
	cout << "result3 = " << result3 << endl;
	cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
	cout << "condition1 = " << condition1 << endl;
	cout << "condition2 = " << condition2 << endl;
	
	return 0;
	
} 
