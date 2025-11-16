#include <iostream>
using namespace std;

class Date {
	private:
		int year;
		int month;
		int day;
	public:
		Date(int y = 0, int m = 0, int d = 0) {
			year = y;
			month = m;
			day = d;
		}
		
		void SetYear(int y) {
			year = y;
		}
		void SetMonth(int m) {
			month = m;
		}
		void SetDay(int d) {
			day = d;
		}
		
		int GetYear() {
			return year;
		}
		int GetMonth() {
			return month;
		}
		int GetDay() {
			return day;
		}
};

int main() {
	Date day;
	day.SetYear(2016);
	day.SetMonth(5);
	day.SetDay(9);
	cout<<day.GetYear()<<"/"<<day.GetMonth()<<"/"<<day.GetDay()<<endl;
	return 0;
}
