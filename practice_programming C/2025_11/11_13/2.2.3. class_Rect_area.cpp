#include <iostream>

using namespace std;

class Rect {
	private:
		int w;
		int h;
	public:
		Rect(int a = 0, int b = 0) {
			w = a;
			h = b;
		}
		input() {
			cin >> w >> h;
		}
		
		int area() {
			return w * h;	
		}
};

int main() {
	Rect r, r1(20, 30);
	r.input();
	cout << r.area() <<endl;
	cout << r1.area() << endl;
	return 0;
}
