#include <iostream>
using namespace std;

class Fraction {
	private:	
		int numerator;
		int denominator;
	public:
		Fraction(int n = 0, int d = 1) {
			numerator = n;
			denominator = d;
		}
		friend istream& operator >> (istream& is, Fraction& f) {
			char ch;
			is >> f.numerator >> ch >> f.denominator;
			return is;
		}
		friend ostream& operator << (ostream& os, Fraction& f) {
			os << f.numerator << "/" << f.denominator;
			return os;
		}
		operator float() {
			return (float)numerator / denominator;
		}
};

int main() {
	Fraction a;
	cin >> a;
	cout << a << endl;
	cout << (float)a << endl;
	return 0;
}
