/*example
output:
blue circle 31400
green rect 2700
red tria 1750 */

#include <iostream>
#include <cstring>
using namespace std;

class shape {
	protected:
		char color[20];
	public:
		shape(const char* p) {
			strcpy(color, p);
		}
		virtual void Draw() = 0; 
};
class rect : public shape {
	int width, height;
	public:
		rect(const char* p, int w, int h) : shape(p) {
			width = w;
			height = h;
		}
		void Draw() {
			cout << color << " rect " << width * height << endl;
		}
};
class circle : public shape {
	int radius;
	public:
		circle(const char* p, int r) : shape(p) {
			radius = r;
		}
		void Draw() {
			cout << color << " circle " << 3.14 * radius * radius << endl;
		}
};
class tria : public shape {
	int height, buttom;
	public:
		tria(const char* p, int h, int b) : shape(p) {
			height = h;
			buttom = b;
		}
		void Draw() {
			cout << color << " tria " << height * buttom / 2 << endl;
		}
};
int main() {
	circle c("blue", 100);
	rect r("green", 30, 90); 
	tria t("red", 50, 70);
	shape* p = &c;
	p->Draw(); 
	p = &r;
	p->Draw();
	p = &t;
	p->Draw();
}
