#include <stdio.h>
#define PI 3.14

typedef struct {
	int x;
	int y;
	int r;
}Circle;

void print_info(Circle a) {
	printf("(%d, %d):%d\n", a.x, a.y, a.r);
}

int get_area(Circle a) {
	return PI * a.r * a.r;
}

Circle enlarge_circle(Circle *pc) {
	pc->r *= 2;
}

int main() {
  	Circle c;
  	scanf("%d%d%d", &c.x, &c.y, &c.r);
  	print_info(c);
  	printf("%d\n", get_area(c));
  	enlarge_circle(&c);
  	print_info(c);
  	return 0;
}
