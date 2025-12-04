#include <iostream>
using namespace std;
#define Max 100

int main() {
	int n_T = 0, m_C = 0;
	int T[Max][Max], C[Max][Max], H[Max][Max], F[Max][Max];
	int n_arr;
	
	cout << "input n_arr: ";
	cin >> n_arr;
	cout << "input T: " << endl;
	for (int i = 0; i < n_arr; i++) {
		for (int j = 0; j < n_arr; j++) {
			cin >> T[i][j];
		}
	}
	cout << "input C: " << endl;
	for (int i = 0; i < n_arr; i++) {
		for (int j = 0; j < n_arr; j++) {
			cin >> C[i][j];
		}
	}
	for (int i = 0; i < n_arr; i++) {
		if (T[i][i] % 2 == 0)
			n_T++;
		if (T[i][n_arr - i - 1] % 2 == 0 && i != (n_arr - i - 1)) {
			n_T++;
		}
	}
	for (int i = 0; i < n_arr; i++) {
		if (C[i][i] % 2 == 0)
			m_C++;
		if (C[i][n_arr - i - 1] % 2 == 0 && i != (n_arr - i - 1)) {
			m_C++;
		}
	}
	if (n_T < m_C) {
		for (int i = 0; i < n_arr; i++) {
			for (int j = 0; j < n_arr; j++) {
				H[i][j] = T[j][i] + n_T * C[i][j];
			}
		}
		cout << "array H: " << endl;
		for (int i = 0; i < n_arr; i++) {
			for (int j = 0; j < n_arr; j++) {
				cout << H[i][j] << " ";
			}
			cout << endl;
		}
	}
	else {
		for (int i = 0; i < n_arr; i++) {
			for (int j = 0; j < n_arr; j++) {
				F[i][j] = C[j][i] + m_C * T[i][j];
			}
		}
		cout << "array F: " << endl;
		for (int i = 0; i < n_arr; i++) {
			for (int j = 0; j < n_arr; j++) {
				cout << F[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
} 
