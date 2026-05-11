#include <iostream>
#include <string>
using namespace std;

int main() {
	string str1 = "I like", str2 = "CPP programming.", str;
	str = str1 + str2;
	cout << str << endl;
	cout << str.length() << endl;
	
	if (str1 < str2) 
		cout << str1 << " < " << str2 << endl;
	else
		cout << str2 << " < " << str1 << endl;
		
	return 0;
}
