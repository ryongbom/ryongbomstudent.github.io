#include <iostream>
using namespace std;
#define Max 100

int main() {
	int array_C[Max][Max];
	int array_T[Max][Max];
	int array_H[Max][Max];
	int array_Z[Max][Max];
	int S1 = 0, S2 = 0;
	int n;
	cout << "input n: ";
	cin >> n; 
	cout << "input array C: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> array_C[i][j];
			if (j == i || j == n - i - 1)
				S1 += array_C[i][j];			
		}
	}
	cout << "input array T: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> array_T[i][j];
			if (j == i || j == n - i - 1)
				S2 += array_T[i][j];	
		}
	}
	if (n % 2 == 1) {
		S1 -= array_C[n / 2][n / 2];
		S2 -= array_T[n / 2][n / 2];
	}
	if (S1 < S2) {
		cout << "Array H: " << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				array_H[i][j] = S1 + S1 * array_T[i][j];
				cout << array_H[i][j] << " "; 
			}
			cout << endl;
		} 
	}
	else {
		cout << "Array Z: " << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				array_Z[i][j] = S2 + S2 * (array_T[i][j] + array_C[i][j]);
				cout << array_Z[i][j] << " ";
			}
			cout << endl;
		}
	}
	
	return 0;
} 
