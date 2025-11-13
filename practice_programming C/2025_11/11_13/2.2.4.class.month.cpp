#include <iostream>
#include <cstring>
using namespace std;

const char *buf[] = { "", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Agu", "Sep", "Oct", "Nov", "Dec" };

class Month {
	private:
		int month;
	public:
		Month(int a = 1) {
			month = a;
		}
		
		Month(const char *mon) {
			for (int i = 0; i < 13; i++) {
				if (strcmp(buf[i], mon) == 0) {
					month = i;
					return;
				}
			}
			month = -1;
		}
		
		display(int temp) {
			if (temp == 0) {
				cout << month << endl;
			}
			else if (temp == 1) {
				cout << buf[month] << endl;
			}
		}
};

int main() {
	Month a, b(4), c("May");
	a.display(0);
	a.display(1);
	b.display(0);
	b.display(1);
	c.display(0);
	c.display(1);
	return 0;
}


