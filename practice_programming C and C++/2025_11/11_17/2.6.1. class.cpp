#include <iostream>
using namespace std;

class Fraction {
	private:
		int dem;
		int num;
		static int count;
		int number;
	public:
		Fraction(int a = 0, int b = 1) {
			dem = a;
			num = b;
			count++;
			number = count;
		}
		~Fraction() {
			count--;	
		}
		int getNumber() {
			return number;
		}
};

int Fraction::count = 0;

int main() {
	Fraction A(1, 2), B, C;
	cout << B.getNumber() << endl;
	cout << A.getNumber() << endl;
	cout << C.getNumber() << endl;
	return 0;
} 
