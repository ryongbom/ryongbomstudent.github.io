#include <iostream>
using namespace std;

double Sum(double a, double b) {
	return a + b;
}

double Raz(double a, double b) {
	return a - b;
}

double ff(double a, double b, double (*f)(double, double)) {
	return f(a, b);
}

int main(void) {
	cout << "=== test1 ===" << endl;
	double q = -44, w = 70;
	double d;
	
	double (*ptr_f)(double, double);
	
	ptr_f = Sum;
	d = ptr_f(q, w);
	cout << d << endl;
	
	ptr_f = Raz;
	d = ptr_f(q, w);
	cout << d << endl;
	
	cout << endl << "=== test2 ===" << endl;
	
	cout << ff(3, 4, Sum) << endl;
	cout << ff(3, 4, Raz) << endl;
	return 0;
}