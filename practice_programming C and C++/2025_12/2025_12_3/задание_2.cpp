#include <iostream>
#define max 100
using namespace std;

int main() {
	int n;
	int C[max][max], T[max][max], F[max][max], H[max][max];
	int a, b, k1 = 0, k2 = 0;
	cout << "input n: ";
	cin >> n;
	cout << "input a, b: ";
	cin >> a >> b;
	cout << "input array C:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> C[i][j];
		}
	}
	cout << "input array T:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> T[i][j];
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = n - i; j < n; j++) {
			if (C[i][j] < a)
				k1++;
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = n - i; j < n; j++) {
			if (T[i][j] < b)
				k2++;
		}
	}
	if (k1 < k2) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				F[i][j] = T[i][j] + 2 * k1 * C[i][j];
			}
		}
		cout << "Array F = T + 2k1C:" << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << F[i][j] << " ";
			}
			cout << endl;
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				H[i][j] = 2 * C[i][j] - k2 * T[i][j];
			}
		}
		cout << "Array H = 2C - k2T:" << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << H[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
} 
