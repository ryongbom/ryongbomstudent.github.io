#include <iostream>
using namespace std;
#define Max 100

int main() {
	int size;
	int C[Max][Max], T[Max][Max], F[Max][Max], H[Max][Max];
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
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (j < i && C[i][j] < 0)
				count_C++; 
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (j < i && T[i][j] < 0)
				count_T++;
		}
	}
	cout << endl;
	cout << "count_C: " << count_C << endl;
	cout << "count_T: " << count_T << endl;
	
	if (count_C > count_T) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				F[i][j] = 0;
				for (int k = 0; k < size; k++) {
					F[i][j] += C[i][k] * T[k][j];
				}
				F[i][j] -= T[j][i];
			}
		}
		cout << "\nresult F = C * T - Tt:" << endl;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << F[i][j] << " ";
			}
			cout << endl;
		}
	} else {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				H[i][j] = C[j][i];
				for (int k = 0; k < size; k++) {
					H[i][j] -= T[i][k] * C[k][j];
				}
			}
		}
		cout << "\nresult H = Ct - T * C:" << endl;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << H[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
