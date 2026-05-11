#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char str[100];
	
	cout << "input sentence: ";
	cin >> str;
	
	int len = strlen(str);
	for (int i = len - 1; i >= 0; i--) {
		cout << str[i];
	}
	cout << endl;
	return 0;
} 
