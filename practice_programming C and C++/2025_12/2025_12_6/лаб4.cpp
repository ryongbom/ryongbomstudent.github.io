#include <iostream>
using namespace std;

int InvertDigits(int);

int main() {
	int number[5];
	for (int i = 0; i < 5; i++) {
		cout << "number " << i + 1 << ":";
		cin >> number[i];
		
		if (number[i] <= 0) {
			cout << "Error!!!" << endl;
			exit(0);
		}
	}
	
	cout << endl;
	cout << "Result:" << endl;
	cout << "=================" << endl;
	
	for (int i = 0; i < 5; i++) {
		int reversed = InvertDigits(number[i]);
		cout << number[i] << "->" << reversed << endl; 
	}
	
	return 0;
}

int InvertDigits(int K) {
	int reversed = 0;
	
	while (K > 0) {
		int digit = K % 10;
		reversed = reversed * 10 + digit;
		K = K / 10;
	}
	
	return reversed;
}
