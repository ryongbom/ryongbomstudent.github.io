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
		
		Fraction operator+(const Fraction& f) {
			Fraction temp;
			temp.denominator = denominator * f.denominator;
			temp.numerator = numerator * f.denominator + f.numerator * denominator;
			return temp; 
		}
		
		Fraction operator+(int i) {
			Fraction temp;
			temp.denominator = denominator;
			temp.numerator = numerator + denominator * i;
			return temp;
		}
		
		void display() {
			cout << numerator << "/" << denominator << endl;
		}
};

int main() {
	Fraction f1(1, 2), f2(1, 3), f;
	f = f1 + f2;
	f.display();
	f = f1 + 1;
	f.display();
	return 0;
}
