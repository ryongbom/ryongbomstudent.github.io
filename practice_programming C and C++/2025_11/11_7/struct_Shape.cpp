#include <stdio.h>
#define PI 3.14

typedef enum {
	RECTANGLE,
	CIRCLE
} SHAPE;

typedef struct {
	int x, y;
} Point;

typedef struct {
	SHAPE kind;
	Point center;
	union {
		struct {
			int lenght, width;
		} rectangle;
		struct {
			int radius;
		} circle;
	} u;
} Shape;

void input(Shape *ps) {
	scanf("%d", &ps->kind);
	if (ps->kind == RECTANGLE)
		scanf("%d%d%d%d", &ps->center.x, &ps->center.y, &ps->u.rectangle.lenght, &ps->u.rectangle.width);
	else if (ps->kind == CIRCLE)
		scanf("%d%d%d", &ps->center.x, &ps->center.y, &ps->u.circle.radius);
} 

void print(Shape sp) {
	if (sp.kind == RECTANGLE)
		printf("Rectangle:(%d, %d), (%d, %d)\n", sp.center.x, sp.center.y, sp.u.rectangle.lenght, sp.u.rectangle.width);
	else if (sp.kind == CIRCLE)
		printf("Circle:(%d, %d), %d\n", sp.center.x, sp.center.y, sp.u.circle.radius);
}

int get_area(Shape s) {
	if (s.kind == RECTANGLE)
		return s.u.rectangle.lenght * s.u.rectangle.width;
	else if (s.kind == CIRCLE)
		return PI * s.u.circle.radius * s.u.circle.radius;
	return 0;
}

Shape move(Shape *ps, Point n) {
	ps->center.x += n.x;
	ps->center.y += n.y;
}

int main() {
	Shape s;
	Point m = {5, 10};
	input(&s);
	print(s);
	printf("%d\n", get_area(s));
	move(&s, m);
	print(s);
	
	return 0;
} 
