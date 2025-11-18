#include <iostream>
#include <cstring>
using namespace std;

class Pupil {
	private:
		char name[100];
		static int count;
	public:
		int num;
		Pupil(const char *p = "NoName") {
			strcpy(name, p);
			num = count;
			count++;
		}
		Pupil(Pupil &p) {
			num = count;
			count++;
			strcpy(name, p.name);
		}
		void setName(char *s) {
			strcpy(name, s);
		}
		static void SetNo(int n) {
			count = n;
		}
		void output() {
			cout << num << ", " << name << endl;
		}
};

int Pupil::count = 1;

int main() {
	Pupil a("ZhangHyokSong");
	Pupil b = a;
	b.setName("RiHyok");
	Pupil::SetNo(5);
	Pupil c;
	a.output();
	b.output();
	c.output();
	return 0;
}
