#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	
	int const Max_size = 16;
	int A[Max_size], M[Max_size];
	int n, i, j;
	int choice;
		
	cout << "input n (1 <= n <= 16): " << endl;
	cin >> n;
	if (n < 1 || n > Max_size)
		cout << "false" << endl;
		
	cout << "seletion method input:" << endl;
	cout << "0 - hand input" << endl;
	cout << "1 - random input" << endl;
	cin >> choice;
	
	if(choice == 0) {
		cout << "input array A:" << endl;
		for (i = 0; i < n; i++) {
			cout << "A[" << i + 1 << "]:";
			cin >> A[i];
		}
	}
	else if(choice == 1) {
		srand(time(NULL));
		cout << "random array A: ";
		cout << "{";
		for (int i = 0; i < n; i++) {
			A[i] = rand() % 201 - 100;
			if (i == n - 1) {
				cout << A[i];
				break;
			}
			cout << A[i] << ", ";
		}
		cout << "}" << endl;
	}
	
	int pos[Max_size], neg[Max_size];
	int count_pos = 0, count_neg = 0;
	
	for (i = 0; i < n; i++) {
		if (A[i] > 0) {
			pos[count_pos++] = A[i];
		}
		else if (A[i] < 0) {
			neg[count_neg++] = A[i];
		}
	}
	 
	for (i = 0; i < count_pos / 2; i++) {
		swap(pos[i], pos[count_pos - 1 - i]);
	}
	
	for (i = 0; i < count_neg / 2; i++) {
		swap(neg[i], neg[count_neg - 1 - i]);
	}
	
	int index = 0;
	for (i = 0; i < count_pos; i++) {
		M[index++] = pos[i];
	}
	for (i = 0; i < count_neg; i++) {
		M[index++] = neg[i];
	}
	
	cout << "Result array M: ";
	cout << "{";
	for (i = 0; i < index; i++) {
		if (i == index - 1){
			cout << M[i];
			break;
		}
		cout << M[i] << ", ";		
	}
	cout << "}" << endl;
	return 0;
}
