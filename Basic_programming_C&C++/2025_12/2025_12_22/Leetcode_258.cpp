/*Given an integer
num, repeatedly add all its digits until the result has only one digit, and return it.*/
#include <iostream>
using namespace std;

int addDigits(int num) {
	if (num <= 0) {
		return 0;
	}
	int sum = 0;
	while (num > 0) {
		sum += (num % 10);
		num /= 10;
	}
	if (sum < 10) return sum;
	return addDigits(sum);
}

int main() {
	int num;
	cin >> num;
	cout << "Since " << addDigits(num) << " has only one digit, return it" << endl;
	return 0;
}

