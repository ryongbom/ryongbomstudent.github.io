#include <iostream>
using namespace std;

class Fraction {
	private:
		int numrator;
		int denominator;
		static int count;
	public:
		
		Fraction(int a = 0, int b = 1) {
			numrator = a;
			denominator = b;
			count++;
		}
		~Fraction() {
			count--;
		}
		
		void output() {
			cout << numrator << "/" << denominator << endl;
		}
		static int HowMany();
};

int Fraction:: count = 0;
int Fraction::HowMany() {
	return count;
}  

int main() {
	Fraction A(3, 5);
	A.output();
	cout << Fraction::HowMany() << endl;
	Fraction *pB = new Fraction(5), C;
	pB -> output();
	C.output();
	cout << Fraction::HowMany() << endl;
	delete pB;
	cout << Fraction::HowMany() << endl;
	return 0;  
}
