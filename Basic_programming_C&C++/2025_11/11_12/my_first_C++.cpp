#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int n;
	cout << "Enter a decimal number: ";
	cin >> n;
	cout << n << " in hexadecimal is: " << hex << n << endl;
	cout << dec << n << " in octal is: " << oct << n << endl;
	cout << setbase(10) << n << " in decimal is: " << n << endl;
	return 0;
}
