#include <iostream>
using namespace std;

class Date {
	private:
		int year;
		int month;
		int day;
	public:
		Date(int y = 0, int mon = 0, int d = 0) 
			: year(y), month(mon), day(d) {}
		void display() {
			cout << year << "/" << month << "/" << day; 
		}
};

class Time {
	private:
		int hour;
		int minute;
		int second;
	public:
		Time(int h = 0, int m = 0, int s = 0)
			: hour(h), minute(m), second(s) {}
		void display() {
			cout << hour << ":" << minute << ":" << second;
		}
};

class DateTime {
	private:
		Date d;
		Time t;
	public:
		DateTime(const Date dt, const Time tm) {
			this->d = dt;//this°¡ Ê­¼Ñ Ë±Ë¦Â×±Â È¸ËÒ(¸êºã°¡ ¼Ú¸ô´óÊÞ ÊïË±°¡ ¸Ë»¶) 
			this->t = tm;
		}

//		DateTime(int y, int mon, int d, int h, int m, int s)
//			: d(y, mon, d), t(h, m, s) {}
		
		Date getDate() {
			return d;
		}
		
		Time getTime() {
			return t;
		}
		
		void display() {
			d.display();
			cout << " ";
			t.display();
			cout << endl;
		}
};

int main() {
	DateTime a(Date(2016,5,13), Time(10,10,0));
//	DateTime a(2016, 5, 13, 10, 10, 0);
	a.display();
	a.getDate().display();
	cout << endl;
	a.getTime().display();
	return 0;
}
