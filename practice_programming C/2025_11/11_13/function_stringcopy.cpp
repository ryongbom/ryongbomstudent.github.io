#include <iostream>

using namespace std;

char *string_copy(char *a, const char *b) {
	int i = 0;
	for (i = 0; b[i]; i++) {
		a[i] = b[i];
	}
	a[i] = '\0';
	return a;
}

char *string_copy(char *a, const char *b, int n) {
	int i = 0;
	for (i = 0; i < n; i++) {
		a[i] = b[i];
	}
	a[i] = '\0';
	return a;
}

int main() {
	 char p[100], q[100] = "School boy"; 
     string_copy(p, q); 
     cout << p << endl; 
     string_copy(p, q, 5); 
     cout << p << endl; 
     return 0; 
} 
