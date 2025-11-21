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
		Point operator++(int) {
			Point temp = *this;
			x += 1;
			y += 1;
			return temp;
		}
		Point operator+(Point other) {
			Point res;
			res.x = x + other.x;
			res.y = y + other.y;
			return res;
		}
		friend ostream& operator << (ostream& os, const Point& p);
		friend istream& operator >> (istream& is, Point& p);
}; 

ostream& operator << (ostream& os, const Point& p) {
	os << "(" << p.x << "," << p.y << ")";
	return os;
}
istream& operator >> (istream& is, Point& p) {
	char ch;
	is >> ch >> p.x >> ch >> p.y >> ch;
	return is; 
}
int main() {
	Point p, p1(1,2), p2;
	cout << p << endl;
	cin >> p;
	p1 = p++;
	cout << p1  << endl;
	cout << p << endl;
	p2 = p + p1;
	cout << p2 << endl;
	return 0;
}
