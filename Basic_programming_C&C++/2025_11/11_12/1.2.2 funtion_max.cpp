#include <iostream>
using namespace std;

int max(int a, int b) {
	if (a > b)
		return a;
	else if (a < b)
		return b;
}

int max(int a, int b, int c) {
	int temp;
	temp = a;
	if (b > a && c > b)
		temp = c;
	else if (b > a && c < b)
		temp = b;
	
	return temp;
}

int max(int *a, int count) {
	int temp = 0;
	int i;
	temp = a[0];
	for(i = 0; i < count; i++) {
		if (a[i] > temp)
			temp = a[i];
	}
	
	return temp;
}

int main() {
	int n, i, buf[100];
	cin >> n;
	for(i = 0; i < n; i ++)
		cin >> buf[i];
	cout << max(buf[0], buf[1]) << endl;
	cout << max(buf[0], buf[1], buf[2]) << endl;
	cout << max(buf, n) << endl;	
	return 0;
}
