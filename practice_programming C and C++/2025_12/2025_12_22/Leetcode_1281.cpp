/*Given an integer number n, return the difference between 
the product of its digits and the sum of its digits.
*/
#include <iostream>
using namespace std;

int subtractProductAndSum(int n) {
	int product = 1;
	int sum = 0;
	while (n > 0) {
		product *= (n % 10);
		sum += (n % 10);
		n /= 10;
	}
	return product - sum;
}

int main() {
	int num;
	cin >> num;
	cout << subtractProductAndSum(num);
	return 0;
} 
