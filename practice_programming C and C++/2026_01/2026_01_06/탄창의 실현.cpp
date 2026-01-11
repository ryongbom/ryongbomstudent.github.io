#include <iostream>
#include <stack> 

using namespace std;

int main() {
	stack<char> s;
	for (char i = 'a'; i <= 'z'; i++)
		s.push(i);
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
	return 0;
} 
