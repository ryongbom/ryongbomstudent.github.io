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
		Time operator+(Time other) {
			Time temp;
			int carry;
			temp.second = second + other.second;
			if (temp.second > 60) {
				temp.second -= 60;
				carry = 1;
			}
			temp.minute = minute + other.minute + carry;
			carry = 0;
			if (temp.minute > 60) {
				temp.minute -= 60;
				carry = 1;
			}
			temp.hour = hour + other.hour + carry;
			if (temp.hour > 24)
				temp.hour -= 24;
			return temp;
		}
		Time operator-(Time other) {
			Time temp;
			int carry;
			temp.second = second - other.second;
			if (temp.second < 0) {
				temp.second += 60;
				carry = 1;
			}
			temp.minute = minute - other.minute - carry;
			carry = 0;
			if (temp.minute < 0) {
				temp.minute += 60;
				carry = 1;
			}
			temp.hour = hour - other.hour - carry;
			if (temp.hour < 0)
				temp.hour += 24;
			return temp;
		}
};
int main() {
	Time a(10, 17, 30), b(20, 25, 55), c;
	c = a + b;
	c.output();
	c = a - b;
	c.output();
	return 0;
}
