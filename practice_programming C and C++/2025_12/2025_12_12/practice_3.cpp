#include <iostream>
using namespace std;

int main() {
	int number[10];
	float num_center;
	float average;
	int sum = 0;
	
	cout << "input 10 positive numbers:" << endl;
	for (int i = 0; i < 10; i++) {
		cin >> number[i];
		if (number[i] <= 0) {
			cout << "must input positive number!" << endl;
			return 1;
		}
	}
	int max = number[0];
	int min = number[0];
	for (int i = 0; i < 10; i++) {
		if (max < number[i])
			max = number[i];
		if (min > number[i])
			min = number[i];
		sum += number[i];
	}
	average = sum / 10.0;
	int temp = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9 - i; j++) {
			if (number[j] > number[j + 1]) {
				temp = number[j];
				number[j] = number[j + 1];
				number[j + 1] = temp;
			}
		}
	}
	num_center = (number[4] + number[5]) / 2.0;
	cout << "maximum number:" << max << endl;
	cout << "minimum number:" << min << endl;
	cout << "average:" << average << endl;
	cout << "central number:" << num_center << endl;
	return 0;
}
