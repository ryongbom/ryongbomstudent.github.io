#include <iostream>
using namespace std;

class Time {
	private:
		int hour;
		int minute;
		int second;
	public:
		Time(int h = 0, int m = 0, int s = 0) {
			hour = h;
			minute = m;
			second = s;
		}
		void output() {
			cout.fill('0');
			cout.width(2);
			cout << hour << ":";
			cout.width(2);
			cout << minute << ":";
			cout.width(2);
			cout << second << endl;
		}
		void standarize() {
			if(second >= 60) {
				minute += second / 60;
				second %= 60;
			}
			if(minute >= 60) {
				hour += minute / 60;
				minute %= 60;
			}
			if(hour >= 24)
				hour %= 24;

			if(second < 0) {
				minute += (second / 60 - 1);
				second = (second % 60) + 60;
			}
			if(minute < 0) {
				hour += (minute / 60 - 1);
				minute = (minute % 60) + 60;
			}
			if(hour < 0) {
				hour = (hour % 24 + 24) % 24;
			}
		}
		bool operator==(Time other) {
			return (second == other.second && minute == other.minute && hour == other.hour);
		}
		bool operator!=(Time other) {
			return (second != other.second || minute != other.minute || hour != other.hour);
		}
		Time operator+=(Time other) {
			second += other.second;
			minute += other.minute;
			hour += other.hour;
			this->standarize();
			return *this;
		}
};

int main() {
	Time a(10, 17, 30), b(20, 25, 55);
	if(a == b)
		cout << "Same" << endl;
	if(a != b)
		cout << "Different" << endl;
	a += b;
	a.output();
	return 0;
}
