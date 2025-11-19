#include<iostream>
using namespace std;

class Fraction {
	private:
		int numerator;
		int denominator;
	public:
		Fraction(int num = 0, int den = 1) {
			numerator = num;
			denominator = den;
		}
		void input() {
			char ch;
			cin >> numerator >> ch >> denominator;
		}
		bool operator<(Fraction f) {	
			return (f.numerator * denominator > f.denominator * numerator);
		}
		bool operator>(Fraction &f) {
			return (f.numerator * denominator < f.denominator * numerator);
		}
		bool operator==(Fraction &f) {
			return (f.numerator * denominator == f.denominator * numerator);
		}
		bool operator!=(Fraction &f) {
			return (f.numerator * denominator != f.denominator * numerator);
		}
		void output() {
			cout << numerator << "/" << denominator << endl;
		}
}; 

int main() {
	Fraction a, b;
	a.input();
	b.input();
	if(a < b)
		cout << "< : ", a.output();
	if(a > b)
		cout << "> : ", a.output();
	if(a == b)
		cout << "==" << endl;
	if(a != b)
		cout << "!=" << endl;
	return 0;
}
