#include <iostream>
using namespace std;

void getBinary(int);

int main() {
	int N;
	cout << "input N: ";
	cin >> N;
	while (N <= 0) {
		cout << "N > 0 ! : ";
		cin >> N;
	}
	
	cout << N << " 's result-> ";
	getBinary(N);
	return 0;
}

void getBinary(int n) {
	if (n > 1) {
		getBinary(n / 2);
	}
	cout << (n % 2);
}
