#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	cout.setf(ios::fixed);
	cout << 21.23 << endl;
	cout << 21.2345678 << endl;
	cout << setprecision(9) << 21.2345678 << endl;
	cout << setprecision(3) << 21.2345678 << endl;
	cout << setprecision(1) << 3.547 << endl;
	return 0;
}
