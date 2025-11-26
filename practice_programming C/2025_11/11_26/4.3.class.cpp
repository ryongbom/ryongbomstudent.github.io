#include <iostream>
using namespace std;

class Point {
	private:
		int x, y;
	public:
		Point(int a = 0, int b = 0) {
			x = a;
			y = b;
		}
};
class Shape {
	private:
		Point center;
	public:
		Shape(Point p) {
			center = p;
		}
}; 
class Circle :public Shape {
	private:
		int radius;
	public:
		Circle(Point pt, int r = 0) :Shape(pt) {
			radius = r;
		}
};
class Rect :public Shape {
	private:
		int width, length;
	public:
		Rect(Point pt, int w = 0, int l = 0) :Shape(pt) {
			width = w;
			length = l;
		}
};

int main() {
	Shape sh(Point(1, 2));
	Circle c(Point(2, 2), 5);
	Rect r(Point(0, 0), 10, 4);
	return 0;
}
