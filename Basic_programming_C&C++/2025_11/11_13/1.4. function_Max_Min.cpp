#include <iostream>

using namespace std;

void Max_Min(int *a, int n, int &max, int &min) { 
	int i;
	max = a[0];
	min = a[0];
	for (i = 1; i < n; i++) {
		if (a[i] > a[i - 1])
			max = a[i];
		else if (a[i] < a[i - 1])
			min = a[i];
	}
}

int main() {
	int a[10], max, min;
	for(int i = 0; i < 10; i++)
		cin >> a[i];
	Max_Min(a, 10, max, min);
	cout << max << endl << min << endl;
	return 0;
}
