#include <iostream>

using namespace std;

class Time{
	private:
		int h;
		int m;
		int s;
	public:
		void input() {
			char ch;
			cin >> h >> ch >> m >> ch >> s;
		}
		
		void display() {
			int carry = 0;
			int i;
			
			while (s >= 60) {
				s -= 60;
				carry++;
			}
			m += carry;
			carry = 0;
			while (m >= 60) {
				m -= 60;
				carry++;
			}
			h += carry;
			cout << h << ":" << m << ":" << s;
		}
};

int main() {
	Time a;	
	a.input();
	a.display();
	return 0;
}
