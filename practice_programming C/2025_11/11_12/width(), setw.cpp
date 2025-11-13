#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int w = 4;
	char str[10];
	cout << "Enter a sentence:\n";
	while (cin >> str) {
		cout.width(w++);
		cout.fill('*');
		cout << str << endl;
//		cout << setw(w++) << str << endl;
	}
	return 0;
}
