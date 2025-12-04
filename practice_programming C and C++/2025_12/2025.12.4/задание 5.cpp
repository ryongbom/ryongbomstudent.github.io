#include <iostream>
using namespace std;
#define Max 100

int main() {
	int k = 0;
	int m = 0;
	int T[Max][Max], C[Max][Max], F[Max][Max];
	float H[Max][Max];
	int size;
	
	cout << "input matrix size: ";
	cin >> size;
	cout << "input matrix T:" << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cin >> T[i][j];
		}
	}
	cout << "input matrix C:" << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cin >> C[i][j];
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i + j > size - 1)
				if (T[i][j] % 2 == 1) 
					k++;
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (C[i][j] % 2 == 1)
				m++;
		}
	}
	cout << "k: " << k << endl;
	cout << "m: " << m << endl;
	
	if (k > m) {
		if (m == 0) {
			cout << "Error!" << endl;
			exit(0);
		}
		float one_over_m = 1.0f / m;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				H[i][j] = one_over_m * T[i][j] + C[i][j];
			}
		}
		cout << "\nresult H = (1/m)T + C: " << endl;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << H[i][j] << " ";
			}
			cout << endl;
		}
	} else {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				F[i][j] = k * (C[i][j] + T[i][j]) + T[i][j];
			}
		}
		cout << "\nresult F = k * (C + T) + T: " << endl;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << F[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
} 
