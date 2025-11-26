#include <iostream>
#define PI 3.14
using namespace std;

struct Point {
	int x;
	int y;
};
class Shape {
	protected:
		Point center;
	public:
		Shape(int a = 0, int b = 0) {
			center.x = a;
			center.y = b;
		}
		void show() {
			cout << "(" << center.x << "," << center.y << ")" << endl;
		}
};
class Rect :public Shape {
	private:
		int width;
		int length;
	public:
		Rect(Point pt, int px = 0, int py = 0) :Shape(pt.x, pt.y) {
			width = px;
			length = py;
		}
		void show() {
			cout << width * length << endl;
		}	
};
class Circle :public Shape {
	private:
		int radius;
	public:
		Circle(Point pt, int r = 0) :Shape(pt.x, pt.y) {
			radius = r;
		}
		void show() {
			cout << PI * radius * radius << endl;
		}
}; 
int main() {
	Point pt;
	cin >> pt.x >> pt.y;
	Shape s(pt.x, pt.y);
	Rect rt(pt, 5, 6);
	Circle c(pt, 5);
	s.show();
	rt.show();
	c.show();
	return 0;
}
