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
		void output() const {
			cout << numerator << "/" << denominator << endl;
		}
};

int main() {  	
  	Fraction f(1, 2);  	
  	f.output();
	return 0;
}
