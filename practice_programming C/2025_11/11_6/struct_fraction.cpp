#include <stdio.h>

struct fraction {
	int num;
	int den;
};

struct fraction fmul(struct fraction a, struct fraction b) {
	struct fraction c;
	c.den = a.den * b.den;
	c.num = a.num * b.num;
	int den = c.den;
	int num = c.num;
	int temp;
	do {
		temp = den % num;
		den = num;
		num = temp;
	}while(temp != 0);
	c.den /= den;
	c.num /= den;
	return c;
}

int main()
{
	struct fraction a, b, c;
	scanf("%d/%d", &a.num, &a.den);
    scanf("%d/%d", &b.num, &b.den);
	c = fmul(a, b);
	printf("%d/%d", c.num, c.den);
	return 0;
}
