#include <iostream>
using namespace std;
#define Max 100

int main() {
	int l, m;
	int size;
	int T[Max][Max], C[Max][Max], A[Max][Max], B[Max][Max];
	int count_T = 0;
	int count_C = 0;
	
	cout << "input matrix's size: ";
	cin >> size;
	cout << "input l: ";
	cin >> l;
	cout << "input m: ";
	cin >> m;
	if (l < 1 || m < 1 || l > size || m > size) {
		cout << "colume indices must be between 1 and " << size << endl;;
		return 1;
	}
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
	if (l < m) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				A[i][j] = l * T[i][j] + m * C[i][j];
			}
		}
		for (int i = 0; i < size; i++) {
			if (T[i][l - 1] > 0)
				count_T++;
		}
		cout << "matrix A:" << endl;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << A[i][j] << " ";
			}
			cout << endl;
		}
		cout << "count positive in colume " << l << "of T: " << count_T << endl; 
	} else {
		int l_square = l * l;
		int m_square = m * m;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				B[i][j] = l_square * C[i][j] + m_square * T[i][j];
			}
		}
		for (int i = 0; i < size; i++) {
			if (C[i][m - 1] > 0) {
				count_C++;
			}
		}
		cout << "matrix B:" << endl;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << B[i][j] << " ";
			}
			cout << endl;
		}
		cout << "count positive in colume " << m << "of C: " << count_C << endl;
	}
	return 0;
}
