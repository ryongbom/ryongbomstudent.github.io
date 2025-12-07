#include <iostream>
using namespace std;

template <class T>
class Array {
	private:
		int size;
		T* buf;
	public:
		Array(int n = 0) {
			size = n;
			buf = new T[n];
		}
		~Array () {
			delete [] buf;
		}
		Array(const Array& other) {
			size = other.size;
			buf = new T [size];
			for (int i = 0; i < size; i++) {
				buf[i] = other.buf[i];
			}
		}
		Array& operator=(const Array& other) {
			if (this != &other) {
				delete [] buf;
				size = other.size;
				buf = new T [size];
				for (int i = 0; i < size; i++) {
					buf[i] = other.buf[i];
				}
			}
			return *this;
		}
		template <class U>
		friend ostream& operator<<(ostream& os, const Array<U>& obj);
		template <class U>
		friend istream& operator>>(istream& is, const Array<U>& obj);
		Array operator+(const Array& obj) {
			int i;
			Array res(size + obj.size);
			for (i = 0; i < size; i++) {
				res.buf[i] = buf[i];
			}
			for (i = 0; i < obj.size; i++) {
				res.buf[size + i] = obj.buf[i];
			}
			return res;
		}
};
template <class T>
ostream& operator<<(ostream& os, const Array<T>& obj) {
	int i;
	for (i = 0; i < obj.size; i++) {
		os << obj.buf[i] << " ";
	}
	os << endl;
	return os;	
}
template <class T>
istream& operator>>(istream& is, const Array<T>& obj) {
	int i;
	for (i = 0; i < obj.size; i++) {
		is >> obj.buf[i];
	}
	return is;	
}
int main() {
	Array<int> a(2), b(4);
	cin >> a >> b;
	Array<int> c;
	c = a + b;
	cout << c;
	return 0;
}
