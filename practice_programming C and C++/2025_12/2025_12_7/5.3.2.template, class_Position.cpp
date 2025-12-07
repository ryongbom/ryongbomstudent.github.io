#include <iostream>
using namespace std;

template <class T>

class Position  {
	private:
		T x;
		T y;
		T z;
	public:
		Position(T a = 0, T b = 0, T c = 0) {
			x = a;
			y = b;
			z = c;
		}
		Position& operator=(const Position& other) {
			if (this != &other) {
				x = other.x;
				y = other.y;
				z = other.z;
			}
			return *this;
		}
		Position operator+(const Position& other) {
			Position<T> m;
			m.x = x + other.x;
			m.y = y + other.y;
			m.z = z + other.z;
			return m;
		}
		Position operator-(const Position& other) {
			Position<T> m;
			m.x = x - other.x;
			m.y = y - other.y;
			m.z = z - other.z;
			return m;
		}
		template <class U>
		friend ostream& operator<<(ostream& os, const Position<U>&);
		template <class U>
		friend istream& operator>>(istream& is, Position<U>&);
}; 

template <class T>
ostream& operator<<(ostream& os, const Position<T>& other) {
	os << "(" << other.x << "," << other.y << "," << other.z << ")";
	return os;
}
template <class T>
istream& operator>>(istream& is, Position<T>& other) {
	char ch;
	is >> ch >> other.x >> ch >> other.y >> ch >> other.z >> ch;
	return is;
}

int main() {
	Position<int> m1,  m2, m3;
	cin >> m1 >> m2;
	m3 = m1 + m2;
	cout << m3 << endl;
	m3 = m1 - m2;
	cout << m3 << endl;
	return 0;
} 
