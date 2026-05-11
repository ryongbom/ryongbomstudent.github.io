/*Given an integer x,return true
if x is a palindrome,and false otherwise.*/
#include <iostream>
using namespace std;

bool isPalindrome(int x) {
	if (x < 0) return false;
	else {
//		int arr[30];
//		int count = 0;
//		int i = 0;
//		while (x > 0) {
//			arr[i++] = x % 10;
//			x /= 10;
//			count++;
//		}
//		for (int i = 0; i < count / 2; i++) {
//			if (arr[i] != arr[count - 1 - i]) {
//				return false;
//				exit(0);
//			}
//		}
//		return true;
		int rev = 0;
		int digit = 0;
		int temp = x;
		while (x > 0) {
			digit = x % 10;
			rev = rev * 10 + digit;
			x /= 10;
		}
		if (temp == rev) return true;
		else return false;	
	}
}

int main() {
	int num;
	cin >> num;
	if (isPalindrome(num) == 1) {
		cout << "true" << endl;
	}
	else cout << "false" << endl;
	return 0;
}

