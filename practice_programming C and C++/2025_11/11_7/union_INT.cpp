#include <stdio.h>

union INT {
	int i;
	unsigned char bytes[4];// ÌÁ ¹ÉµÛÌ© ±¶ºã¶¦ 4±¶µá Â×²÷°¡? 
};

void display(union INT a) {
	printf("%d %d", a.bytes[0], a.bytes[3]);
}

int main() {
	union INT a;
	scanf("%d", &a.i);
	display(a);
	return 0;
} 
