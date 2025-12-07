#include <iostream>
using namespace std;
#define Max 100

int main() {
	int m;
	int k;
	int size;
	int C[Max][Max], T[Max][Max], B[Max][Max], D[Max][Max];
	int num_B = 0;
	int num_D = 0;
	
	cout << "input matrix's size: ";
	cin >> size;
	cout << "input m: ";
	cin >> m;
	cout << "input k: ";
	cin >> k;
	if (m < 1 || k < 1 || m > size || k > size) {
		cout << "error! again input:" << endl;
		return 1;
	}
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
			B[i][j] = T[i][j] - k * C[i][j];
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			D[i][j] = C[i][j] + m * T[i][j];
		}
	}
	for (int i = 0; i < size; i++) {
		if (B[i][m - 1] > 1) {
			num_B = B[i][m - 1];
			break;
		}
	}
	for (int i = 0; i < size; i++) {
		if (D[i][k - 1] > 1) {
			num_D = D[i][k - 1];
			break;
		}
	}
	cout << "num_B: " << num_B << endl;
	cout << "num_D: " << num_D << endl;
	return 0;
}
