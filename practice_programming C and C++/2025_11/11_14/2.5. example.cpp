#include <iostream>
using namespace std;

class Date {
		int y, m, d;
	public:
		Date(int a = 0, int b = 0, int c = 0) {
			y = a;
			m = b;
			d = c;
		}
		void display() {
			cout << y << "/" << m << "/" << d;
		}
};

class Time {
		int h, m, s;
	public:
		Time(int a = 0, int b = 0, int c = 0) {
			h = a;
			m = b;
			s = c;
		}
		void display() {
			cout << h << ":" << m << ":" << s ;
		}
};

class DateTime {
		Date date;
		Time time;
	public:
		DateTime(const Date dt, const Time tm) {
			date = dt;
			time = tm;
		}
		Date getDate() {
			return date;
		}
		Time getTime() {
			return time;
		}
		void display() {
			date.display();
			cout << " ";
			time.display();
			cout << endl;
		}
};

int main() {
	DateTime a(Date(2016,5,13), Time(10, 10,0));
	a.display();
	a.getDate().display();
	cout << endl;
	a.getTime().display();
	return 0;
}
