#include <stdio.h>

typedef struct{
	int hh;
	int mm;
	int ss;
}Time;

Time sub(Time t, int s) {
	Time newt;
	int carry = 0;
	int temp = 0;
	while (t.ss < s) {
		t.ss += 60;
		carry++;
	}
	newt.ss = t.ss - s;
	t.mm -= carry;
	while (t.mm < 0) {
		t.mm += 60;
		temp++;
	}
	newt.mm = t.mm;
	newt.hh = t.hh - temp;
	return newt;
}

void print(Time newt) {
		printf("%02d:%02d:%02d", newt.hh, newt.mm, newt.ss);
}

int main() {
	Time a;
	int b;
	scanf("%d:%d:%d", &a.hh, &a.mm, &a.ss);
	scanf("%d", &b);
	print( sub(a, b) );
	return 0;
}
