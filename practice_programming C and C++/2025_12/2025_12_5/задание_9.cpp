#include <iostream>
using namespace std;
#define Max 100

int main() {
	int size = 0; 
	int C[Max][Max], T[Max][Max], H[Max][Max], F[Max][Max];
	int sum_C = 0;
	int sum_T = 0;
	
	cout << "input size of matrix: ";
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
			if (i + j == size - 1 && C[i][j] % 2 == 0)
				sum_C += C[i][j];
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i + j == size - 1 && T[i][j] % 2 == 0)
				sum_T += T[i][j];
		}
	}
	cout << endl;
	cout << sum_C << endl;
	cout << sum_T << endl;
	if (sum_C > sum_T) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				H[i][j] = T[i][j] + 2 * C[i][j];
			}
		}
		cout << "\nresult H = T + 2C:" << endl;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << H[i][j] << " ";
			}
			cout << endl;
		}
	} else {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				F[i][j] = C[i][j] - 5 * T[i][j];
			}
		}
		cout << "\nresult F = C - 5T:" << endl;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << F[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
