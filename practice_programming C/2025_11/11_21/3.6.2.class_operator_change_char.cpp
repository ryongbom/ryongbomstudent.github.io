#include <iostream>
#include <string.h>
using namespace std;

class String {
	private:
		char *buf;
		int len;
	public:
		String(const char *s = "") {
			len = strlen(s);
			buf = new char [len + 1];
			strcpy(buf, s);
		}
		~String() {
			delete [] buf;
		}
		friend istream& operator >> (istream& is, String &s) {
//			char temp[1000];
//			is.getline(temp, 1000);
//			delete [] s.buf;
//			s.len = strlen(temp);
			s.buf = new char [10];
//			strcpy(s.buf, temp);
			is >> s.buf;
//			return is;
		}
		operator char*() {
			return (char*) buf;
		}
};
int main() {
	String s;
	cin >> s;
	cout << (char*)s << endl;
	return 0;
}
