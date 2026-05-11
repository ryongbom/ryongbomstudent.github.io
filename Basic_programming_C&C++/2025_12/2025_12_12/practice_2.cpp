#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	bool result = true;
	cout << "input n: ";
	cin >> n;
	if (n <= 1) {
		cout << "n must be n > 1!" << endl;
		return 1;
	}
	for (int i = 2; i * i < n; i++) {
		if (n % i == 0) {
			result = false;
			break;
		}
	}
	if (result) {
		cout << "n is prime number!" << endl;
	} else {
		cout << "n is not prime number!" << endl;
	}
	return 0;
}
