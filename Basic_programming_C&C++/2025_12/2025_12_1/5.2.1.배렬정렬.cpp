#include<iostream>
using namespace std;
template<class T>

void sort(T *array, int n) {
	T temp;
	for(int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (array[i] > array[j]) {
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	} 
}
int main() {
	int i, a[5] = {5, 2, 1, 3, 4};
	float b[5] = {1.7, -5.3, 6.7, 0, 9.1};
	sort(a, 5);
	sort(b, 5);
	for(i = 0; i < 5; i++)
		cout << a[i] << " ";
	cout << endl;
	for(i = 0; i < 5; i++)
		cout << b[i] << " ";
	cout << endl;
	return 0;
} 
