#include <iostream>
using namespace std;
#define Max 100

int main() {
	int size;
	int T[Max][Max], C[Max][Max], H[Max][Max], F[Max][Max];
	int count_C = 0;
	int count_T = 0;
	
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
	for (int j = 0; j < size; j++) {
		if (C[0][j] == C[1][j])
			count_C++;
	}
	for (int j = 0; j < size; j++) {
		if (T[size - 1][j] == T[size - 2][j])
			count_T++;
	}
	cout << endl;
	cout << "count_C: " << count_C << endl;
	cout << "count_T: " << count_T << endl;
	if (count_C > count_T) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				H[i][j] = 0;
				for (int k = 0; k < size; k++) {
					H[i][j] += T[i][k] * C[k][j];
				}
				H[i][j] += 2 * C[i][j];
			}
		}
		cout << "\nresult H = T * C + 2 * C:" << endl;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << H[i][j] << " ";
			}
			cout << endl;
		}
	} else {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				F[i][j] = 0;
				for (int k = 0; k < size; k++) {
					F[i][j] -= C[i][k] * T[k][j];
				}
				F[i][j] += 3 * T[i][j];
			}
		}
		cout << "\nresult F = 3 * T - C * T:" << endl;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << F[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
} 
