#include <iostream>
using namespace std;
#define Max 100

int main() {
	int size;
	int k1 = 0;
	int k2 = 0;
	int C[Max][Max], T[Max][Max], H[Max][Max], F[Max][Max];
	
	cout << "input matrix's size: ";
	cin >> size;
	cout << "input matrix C:" << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cin >> C[i][j];
		}
	}
	cout << "input matrix T:" << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cin >> T[i][j];
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (j > i && T[i][j] % 5 == 0 && T[i][j] > 0)
				k1++;
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (j > i && C[i][j] % 3 == 0 && C[i][j] > 0)
				k2++;
		}
	}
	if (k1 > k2) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				F[i][j] = 0;
				for (int k = 0; k < size; k++) {
					F[i][j] += T[i][k] * C[k][j];
				}
				F[i][j] += 3 * C[i][j];
			}
		}
		cout << "matrix F:" << endl;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << F[i][j] << " ";
			}
			cout << endl;
		}
	} else {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				H[i][j] = 5 * T[i][j];
				for (int k = 0; k < size; k++) {
					H[i][j] += C[i][k] * T[k][j];
				}
			}
		}
		cout << "matrix H:" << endl;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << H[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
} 
