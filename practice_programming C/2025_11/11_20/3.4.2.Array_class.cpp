#include <iostream>
using namespace std;

class Array {
	private:
		int count;
		int *buf;
	public:
		Array(int n = 0) {
			count = n;
			buf = new int [count];
			for (int i = 0; i < count; i ++) {
				buf[i] = 0;
			}
		}
		~Array() {
			delete [] buf;
		}
		friend istream& operator >> (istream& is, Array &f) {
			for (int i = 0; i < f.count; i++) {
				is >> f.buf[i];
			}
			return is;
		}
		friend ostream& operator << (ostream& os, Array &arr) {
			for (int i = 0; i < arr.count; i++) {
				os << arr.buf[i] << " ";
			}
			return os;
		}
		int& operator[](int index) {
			return buf[index];
		}	
};

int main() {
    Array a(10);
    cout << a << endl;
    cin >> a;
    cout << a << endl;
    a[5] = 20;
    cout << a[5] << endl;
    return 0;
}
