#include <iostream>
using namespace std;
template<class AnyType>

void Swap(AnyType &a, AnyType &b) {
	AnyType temp;
	temp = a;
	a = b;
	b = temp;
}

int main() {
	int i = 10, j = 20;
	double x = 10.1, y = 23.3;
	char a = 'A', b = 'B';
	cout << "origin i and j: " << i << " " << j << endl;
	cout << "origin x and y: " << x << " " << y << endl;
	cout << "origin a and b: " << a << " " << b << endl;
	
	Swap(i, j);
	Swap(x, y);
	Swap(a, b);
	
	cout << "after i and j: " << i << " " << j << endl;
	cout << "after x and y: " << x << " " << y << endl;
	cout << "after a and b: " << a << " " << b << endl;
	return 0; 
}
