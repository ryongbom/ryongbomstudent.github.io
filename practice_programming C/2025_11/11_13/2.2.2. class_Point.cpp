#include <iostream>

using namespace std;

class Point {
	private:
		int x;
		int y;
	public:
		Point(int a = 0, int b = 0) {
			x = a;
			y = b;
		}
		
		void input() {
			char ch;
			cin >> ch >> x >> ch >> y >> ch;
		}
		
		void display() {
			cout << "(" << x << "," << y << ")" << endl;
		}
		
		Point add(Point f) {
			Point result;
			result.x = x + f.x;
			result.y = y + f.y;
			return result;
		}
};

int main() {
	Point p, p1(1,2), p2;
	p.display();
	p.input();
	p2 = p.add(p1);
	p2.display();
	return 0;
}

