#include <iostream>
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
			int n, d;
			char ch;
			cin >> n >> ch >> d;
			numerator = n;
			denominator = d;
		}
		Fraction operator+(Fraction &f) {
			Fraction temp;
			temp.denominator = denominator * f.denominator;
			temp.numerator = numerator * f.denominator + f.numerator * denominator;
			return temp;
		}
		Fraction operator-(Fraction &f) {
			Fraction temp;
			temp.denominator = denominator * f.denominator;
			temp.numerator = numerator * f.denominator - f.numerator * denominator;
			return temp;
		}
		void output() {
			cout << numerator << "/" << denominator << endl;
		}
};

int main() {
	Fraction a, b, c;
	a.input();
	b.input();
	c = a + b;
	c.output();
	c = a - b;
	c.output();
	return 0;
}
