#include <iostream>
using namespace std;
#define Max 100

int main() {
	int k1 = 0;
	int k2 = 0;
	int size;
	int n_T, n_C;
	int T[Max][Max], C[Max][Max], S[Max][Max], F[Max][Max];
	
	cout << "input size: ";
	cin >> size;
	cout << "input n_T: ";
	cin >> n_T;
	cout << "input n_C: ";
	cin >> n_C;
	cout << "input matrix T:" << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cin >> T[i][j];
		}
	}
	cout << "input matrix C:" << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j ++) {
			cin >> C[i][j];
		}
	} 
	for (int i = 0; i < size; i++) {
		if (T[n_T - 1][i] < 7)
			k1++;
	}
	for (int i = 0; i < size; i++) {
		if (C[n_C - 1][i] < 12)
			k2++;
	}
	if (k1 < k2) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				S[i][j] = T[i][j] + (k1 + k2) * C[i][j];
			}
		}
		cout << "\nresult S = T + (k1 + k2)C: " << endl;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << S[i][j] << " ";
			}
			cout << endl;
		}
	} else {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				F[i][j] = k1 * T[i][j] + k2 * C[i][j];
			}	
		}
		cout << "\nresult F = k1 * T + k2 * C: " << endl;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << F[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
