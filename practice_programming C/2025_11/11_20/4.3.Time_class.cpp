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
		int& operator[](int index) {
			if (index == 0)
				return hour;
			if (index == 1)
				return minute;
		}
		friend istream& operator >> (istream& is, Time& other);
		friend ostream& operator << (ostream& os, const Time& other); 
};
istream& operator >> (istream& is, Time& other) {
	char ch;
	is >> other.hour >> ch >> other.minute >> ch >> other.second;
	return is;
}
ostream& operator << (ostream& os, const Time& other) {
	if (other.hour < 13)
		os << other.hour << ":" << other.minute << ":" << other.second << " AM";
	else
		os << (other.hour - 12) << ":" << other.minute << ":" << other.second << " PM";
}
int main() {
	Time t;
	cin >> t;
	cout << t << endl;
	cout << t[0] << "h" << t[1] << "m" << endl;
	return 0;
}
