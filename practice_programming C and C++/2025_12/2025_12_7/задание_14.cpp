#include <iostream>
using namespace std;
#define Max 100

int main() {
	int S = 0;
	int P = 0;
	int size;
	int T[Max][Max], C[Max][Max], F[Max][Max], H[Max][Max];
	
	cout << "Input matrix's size: ";
	cin >> size;
	cout << "Input matrix T:" << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cin >> T[i][j];
		}
	}
	cout << "Input matrix C:" << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cin >> C[i][j];
		}
	}
	for (int i = 0; i < size; i++) {
		S += T[i][size - 1];
		S += T[size - 1][i];
	}
	for (int i = 0; i < size; i++) {
		P += C[i][size - 1];
		P += C[size - 1][i];
	}
	if (S > P) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				F[i][j] = C[i][j] + 2 * T[j][i];
			}
		}
		cout << "\nresult F = C + 2Tt" << endl;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << F[i][j] << " ";
			}
			cout << endl;
		}
	} else {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				H[i][j] = T[i][j] + 5 * C[j][i];
			}
		}
		cout << "\nresult H = T + 5Ct" << endl;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << H[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
