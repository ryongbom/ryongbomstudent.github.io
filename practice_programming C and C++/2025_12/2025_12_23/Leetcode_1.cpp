#include <iostream>
#include <vector>
using namespace std;

//vector<int> twoSum(vector<int>& nums, int target) {
//	for (int i = 0; i < nums.size(); i++) {
//		for (int j = i + 1; j < nums.size(); j++) {
//			if (nums[i] + nums[j] == target) {
//				return {i, j};
//				break;
//			}
//		}
//	}
//}

int main() {
	vector<int> num;
	int n;
	vector<int> v;
	int target;
	cout << "input size of numbers: ";
	cin >> n;
	cout << "input " << n << " numbers: ";
	while(n--) {
		int x;
		cin >> x;
		num.push_back(x);
	}
	cout << "input target: ";
	cin >> target;
//	v = twoSum(num, target);
//	for(int i = 0; i < v.size(); i++) {
//		cout << v[i] << " ";
//	}
	for (int i = 0; i < num.size(); i++) {
		for (int j = i + 1; j < num.size(); j++) {
			if (num[i] + num[j] == target) {
				cout << "[" << i + 1 << ", " << j + 1 << "]";
				break;
			}
		}
	}
	cout << endl;
	return 0;
}
