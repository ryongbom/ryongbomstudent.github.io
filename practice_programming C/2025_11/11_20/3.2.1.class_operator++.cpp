#include <iostream>
using namespace std;

class Fraction {
	private:
		int num;
		int den;
	public:
		Fraction(int n = 0, int d = 1) {
			num = n;
			den = d;
		}
		void input() {
			char ch;
			cin >> num >> ch >> den;
		}
		void output() {
			cout << num << "/" << den << endl;
		}
		Fraction& operator ++() {
			num += den;
			return *this;
		}
		Fraction operator ++(int) {
			Fraction temp = *this;
			num += den;
			return temp;
		}  
}; 

int main() {
	Fraction a, b;
	a.input();
	b = a++;
	a.output();
	b.output();
	b = ++a;
	a.output();
	b.output();
	return 0;
}
