#include <iostream>
using namespace std;
#define Max 100

int main() {
	int T[Max][Max], C[Max][Max], H[Max][Max], F[Max][Max];
	int a = 0, b = 0;
	int n;
	cout << "input n: ";
	cin >> n;
	cout << "input array T: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> T[i][j];
		}
	}
	cout << "input array C: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> C[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			a += T[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			b += C[i][j];
		}
	}
	if (a > b) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				H[i][j] = T[i][j] - a * b * C[i][j];
			}
		}
		cout << "Array H = T - abC: " << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << H[i][j] << " ";
			}
			cout << endl;
		} 
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				F[i][j] = C[i][j] + a * T[i][j];
			}
		}
		cout << "Array F = C + aT: " << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << F[i][j] << " ";
			}
			cout << endl;
		} 
	}
	return 0;
}
