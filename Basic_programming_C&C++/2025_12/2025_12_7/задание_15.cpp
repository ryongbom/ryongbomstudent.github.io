#include <iostream>
using namespace std;
#define Max 100

int main() {
	int k, m;
	int n_countC = 0;
	int l_countT = 0;
	int size;
	int C[Max][Max], T[Max][Max], H[Max][Max], F[Max][Max];
	
	cout << "Input matrix's size: ";
	cin >> size;
	cout << "Input number k: ";
	cin >> k;
	cout << "Input number m: ";
	cin >> m;
	
	cout << "Input matrix C:" << endl;
	for (int i = 0; i < size; i++) {
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
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (C[i][j] != k) {
				n_countC++;
			}
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (T[i][j] != m) {
				l_countT++;
			}
		}
	}
	cout << n_countC << endl;
	cout << l_countT << endl;
	if (n_countC > l_countT) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				H[i][j] = 0;
				for (int p = 0; p < size; p++) {
					H[i][j] += T[p][i] * C[p][j];
				}
				H[i][j] += k * T[i][j];
			}
		}
		cout << "\nresult H = Tt * C + k * T:" << endl;
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
				for (int p = 0; p < size; p++) {
					F[i][j] += C[p][i] * T[p][j];
				}
				F[i][j] += l_countT * C[i][j];
			}
		}
		cout << "\nresult F = Ct * T + l * C:" << endl;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << F[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
