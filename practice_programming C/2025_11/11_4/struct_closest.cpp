#include <stdio.h>
#include <math.h>

typedef struct {
	int x;
	int y;
}Point;

float get_r(int a, int b) {
	float r;
	r = sqrt(a * a + b * b);
	return r;
}

Point get_closest(Point p[], int n) {
	Point result;
	float temp = get_r(p[0].x, p[0].y);
	result = p[0];
	int i, j = 0;
	for (i = 0; i < n; i++)
	{
		if (get_r(p[i].x, p[i].y) < temp) {
			temp = get_r(p[i].x, p[i].y);
			result = p[i];
		}
	}
	return result;
}

int main() {
	Point points[100], closest;
	int n, i;
	scanf("%d", &n);
	
	for (i = 0; i < n; i++)
		scanf("%d%d", &points[i].x, &points[i].y);
	
	closest = get_closest(points, n);
	printf("%d %d", closest.x, closest.y);
  	return 0;
}
