#include <iostream>

using namespace std;

class Fraction {
	private:
		int num;
		int den;
	public:
		Fraction(int a = 0, int b = 0) {
			num = a;
			den = b;
		}
		
		Fraction add(Fraction f) {
			Fraction res;
			res.num = num * f.den + f.num * den;
			res.den = den * f.den;
			return res;
		}
		
		void display() {
			cout << num << '/' << den << endl;
		}
};

int main() {
	Fraction a, b(7, 3), c(2, 3);
	a = b.add(c);
	a.display();
	return 0;
}
