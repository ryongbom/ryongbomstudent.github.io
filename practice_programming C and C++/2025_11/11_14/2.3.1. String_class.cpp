#include <iostream>
#include <cstring>
using namespace std;

class String {
	private:
		char *str;
	public:
		String(const char* p = "") {
			str = new char[strlen(p) + 1];
			strcpy(str, p);
		}
		
		String(const String& other) {
			str = new char[strlen(other.str) + 1];
			strcpy(str, other.str);
		}
		
		~String() {
			delete [] str;
		}
		
		void input() {
			char s[1000];
			cin.getline(s, 1000);
			str = new char[strlen(s) + 1];
			strcpy(str, s);
		}
		
		void display() {
			cout << str << endl;
		}
		
};

int main() {
	String a, b("Hello");
	String c = b;
	a.input();
	a.display();
	c.display();
	return 0;
}
