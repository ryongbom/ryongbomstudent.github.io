#include <iostream>
#include <string.h>
using namespace std;

int main() {
	char str1[] = "I like ", str2[] = "CPP programming.";
	char str[100];
	strcpy(str, str1);
	strcat(str, str2);
	cout << str << endl;
	cout << strlen(str) << endl;
	
	if (strcmp(str1, str2) == -1)
		cout << str1 << " < " << str2 << endl;
	else
		cout << str2 << " < " << str1 << endl;
	
	return 0;
} 
