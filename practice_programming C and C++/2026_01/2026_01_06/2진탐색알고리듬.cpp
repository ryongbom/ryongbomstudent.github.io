#include <iostream>
#include <vector>
using namespace std;

//2¼êÀµ»°Ê²°Ö¶®´Í°éÂï 
int binary_search(const vector<int>& arr, int target) {
	int left = 0;
	int right = arr.size() - 1;
	
	while (left <= right) {
		int mid = left + (right - left) / 2;
		
		if (arr[mid] == target) {
			return mid;
		}
		else if (arr[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}	
	return -1;
}

int main() {
	//¼³µÛ´ô ¹ÉµÛ »¶ºÂ 
	vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
	int target = 11;
	
	int result = binary_search(arr, target);
	
	if (result != -1) {
		cout << "found index: " << result << endl;
		cout << "value: " << arr[result] << endl;
	} else {
		cout << "Can not find index!" << endl;
	}
	return 0;
}

 
