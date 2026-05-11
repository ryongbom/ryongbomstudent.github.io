#include <iostream>

using namespace std;

int *sort(int *b, int n) {
	int i, j;
	int temp;
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (b[i] > b[j]) {
				temp = b[i];
				b[i] = b[j];
				b[j] = temp;
			}
		}
	}
	b[i] = '\0';
	return b;
}

int *sort(int *b, int n, int cor) {
	int i, j;
	int temp;
	if (cor == 1) {
		for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (b[i] < b[j]) {
				temp = b[i];
				b[i] = b[j];
				b[j] = temp;
			}
		}
	}
	b[i] = '\0';
	return b;
	}
}

void print(int *array, int n) {
	int i;
	for (i = 0; i < n; i++)
		cout << array[i] << " ";
	cout << endl;
}

int main() {
	int buf[5] = {1, 5, 3, 8, 4};
	sort(buf, 5); 
	print(buf, 5);
	sort(buf, 5, 1);
	print(buf, 5);
	return 0;
}
