#include <iostream>
using namespace std;

template<class T>
T max(T *arr, int n) {
	T temp_max = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > temp_max) {
			temp_max = arr[i];
		}
	}
	return temp_max;
}

template<class T> //·ô¸Ü ¶®Ë¦ÂÚÆÁ¶ë³Ş ººÊÎÃÍ¼Ñ±¨ 
T min(T *arr, int n) {
	T temp_min = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] < temp_min) {
			temp_min = arr[i];
		}
	}
	return temp_min;
}
int main() {
	int i, a[5] = {5, 2, 1, 3, 4};
	float b[5] = {1.7, -5.3, 6.7, 0, 9.1};
	cout << max(a, 5) << " " << min(a, 5) << endl;
	cout << max(b, 5) << " " << min(b, 5) << endl;
	return 0;	
} 
