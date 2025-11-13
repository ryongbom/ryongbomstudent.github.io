#include <iostream>
#include <cctype>

using namespace std;

int main() {
	char str[100];
	int i;
	cin.getline(str, 100);
	for (i = 0; str[i]; i++)
	{
		if (islower(str[i]))
			str[i] = toupper(str[i]);
		else if (isupper(str[i]))
			str[i] = tolower(str[i]);
	}
	cout << str << endl;
	return 0;
}
