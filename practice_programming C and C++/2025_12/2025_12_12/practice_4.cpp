#include <iostream>
using namespace std;

int getGcdNumber(int a, int b) {
	if (b == 0) {
		return a;
	} 
	return getGcdNumber(b, a % b);
} 

int main() {
	int a, b;
	cout << "input number a, b: ";
	cin >> a >> b;
	if (a == 0 && b == 0) {
		cout << "Both numbers are zero!" << endl;
		return 1;
	}
	int c = getGcdNumber(a, b);
	cout << "GCD:"<< c << endl;
	return 0;
}
