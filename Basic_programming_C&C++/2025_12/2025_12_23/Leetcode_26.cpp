#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, value;
	cin >> n;
	vector<int> v;
	
	for (int i = 0; i < n; i++) {
		cin >> value;
		v.push_back(value);
	}
	
	int count = 0;
    int arr[100];
    for (int i = 0; i < v.size(); i++) {
        arr[i] = 1;
    }
    for (int i = 0; i < v.size(); i++) {
        if (arr[i] != 0) {
    	    for (int j = i + 1; j < v.size(); j++) {
                if (v[i] == v[j]) arr[j] = 0;
            }
        }  
    }
    for (int i = 0; i < v.size(); i++) {
        cout << arr[i] << " ";
    }
	cout << endl;
	return 0;
}
