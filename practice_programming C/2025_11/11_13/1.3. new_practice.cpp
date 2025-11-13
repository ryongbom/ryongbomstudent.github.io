#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int n;
	int i, j;
	cin >> n;
	char **Str = new char* [20];
	for (i = 0; i < n; i++)
		Str[i] = new char[20];
	for (i = 0; i < n; i++)
		cin >> Str[i];
		
	char *temp;
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (strcmp(Str[i], Str[j]) > 0) {
				temp = Str[i];
				Str[i] = Str[j];
				Str[j] = temp; 
			}
		}
	}
	for (i = 0; i < n; i++) {
		cout << Str[i] << endl;
	}
	return 0;
}
