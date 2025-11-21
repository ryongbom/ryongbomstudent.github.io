#include <iostream>
#include <string.h>
using namespace std;

class String {
	private:
		char *buf;
		int len;
	public:
		String(const char* s = "") {
			len = strlen(s);
			buf = new char [len + 1];
			strcpy(buf, s); 
		}
		String(const String& other) {
			len = other.len;
			buf = new char [len + 1];
			strcpy(buf, other.buf);
		}
		~String() {
			delete [] buf;
		}
		friend istream& operator >> (istream& is, String& s) {
			char tmp[1000];¡¡ 
			is.getline(tmp, 1000);
			delete [] s.buf; // ÌÁ¡¡ÃÍ½£ÃÍ¡¡¼Ñ²÷°¡¡© 
			s.len = strlen(tmp);
			s.buf = new char [s.len + 1];
			strcpy(s.buf, tmp);
			return is;
		}
		friend ostream& operator << (ostream& os, String& s) {
			os << s.buf;
			return os;
		}
		String operator +(const String& other) {
			String res;
			res.len = len + other.len;
			res.buf = new char [res.len + 1];
			strcpy(res.buf, buf);
			strcat(res.buf, other.buf);
			return res;
		}
		String operator +=(const String& other) {
			*this = *this + other;
			return *this;
		}
		String& operator =(const String& other) {
			delete [] buf;
			len = other.len;
			buf = new char [len + 1];
			strcpy(buf, other.buf);
			return *this;
		}
};

int main() {
	String s, s1, s2;
	cin >> s1 >> s2;
	s = s1 + s2;
	cout << s << endl;
	s2 += s1;
	cout << s2 << endl;
	return 0;
}
