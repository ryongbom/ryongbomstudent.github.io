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
		void display() {
			cout << numerator << "/" << denominator << endl;
		}
		friend Fraction operator+(int, Fraction);
};

Fraction operator+(int i, Fraction f) {
	Fraction temp;
	temp.numerator = i * f.denominator + f.numerator;
	temp.denominator = f.denominator;
	return temp;
} 

int main() {
	Fraction f1(1, 2), f;
	f = 2 + f1;
	f.display();
	return 0;
}
