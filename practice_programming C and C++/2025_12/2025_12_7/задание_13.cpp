#include <iostream>
using namespace std;
#define Max 100

int main() {
	int size;
	int m, n;
	int A[Max][Max], B[Max][Max], T[Max][Max], C[Max][Max];
	bool condition = false;
	
	cout << "Input matrix's size: ";
	cin >> size;
	cout << "Input number m: ";
	cin >> m;
	cout << "Input number n: ";
	cin >> n;
	
	if (m < 1 || m > size || n < 1 || n > size) {
		cout << "number m must be 0 < m <= size, number n must be 0 < n <= size!" << endl;
		return 1;
	}
	
	cout << "Input matrix C:" << endl;
	for (int i = 0; i < size; i ++) {
		for (int j = 0; j < size; j++) {
			cin >> C[i][j];
		}
	}
	cout << "Input matrix T:" << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cin >> T[i][j];
		}
	}
	bool hasNegativeInCRow = false;
	bool hasPositiveInTRow = false;
	
	for (int i = 0; i < size; i++) {
		if (C[m - 1][i] < 0) {
			hasNegativeInCRow = true;
			break;
		}	
	}
	for (int i = 0; i < size; i++) {
		if (T[n - 1][i] > 0) {
			hasPositiveInTRow = true;
			break;
		}
	}
	condition = (hasNegativeInCRow && hasPositiveInTRow);
	
	if (condition) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				A[i][j] = -C[i][j];
				for (int k = 0; k < size; k++) {
					A[i][j] += T[i][k] * C[k][j];
				}
			}
		}
		cout << "\nresult matrix A = -C + T * C:" << endl;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << A[i][j] << " ";
			}
			cout << endl;
		}
	} else {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				B[i][j] = -T[i][j];
				for (int k = 0; k < size; k++) {
					B[i][j] += C[i][k] * T[k][j];
				}
			}
		}
		cout << "\nresult matrix B = -T + C * T:" << endl;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << B[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
} 
