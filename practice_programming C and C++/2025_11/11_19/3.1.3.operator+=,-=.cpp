#include <iostream>
using namespace std;

inline int gcd(int a, int b) {
	int r;
	while(b) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}
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
		void reduce() {
			int t = gcd(num, den);
			if (t < 0)
				t = -t; 
			num /= t;
			den /= t;
		}
		Fraction operator+=(Fraction other) {
			Fraction res;
			res.den = den * other.den;
			res.num = num * other.den + other.num * den;
			res.reduce();
			*this = res;
			return *this; // c = a + b Ëæº·²÷ c°ªË¾ ´®µØ¼Ñ·² ´óÊî¼è¶í a += bËæº·²÷ a°û »ô»¦Ë¾ ´®µØ¼ÑÊÌÊ¿ ÂÙ³Þ. 
		}
		Fraction operator-=(Fraction other) {
			Fraction res;
			res.den = den * other.den;
			res.num = num * other.den - other.num * den;
			res.reduce();
			*this = res;
			return *this;
		}
};

int main() {
	Fraction a, b;
	a.input();
	b.input();
	a += b;
	a.output();
	a -= b;
	a.output();
	return 0;
}
