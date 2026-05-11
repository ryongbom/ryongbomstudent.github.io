#include <stdio.h>
#include <stdlib.h>

int main() {
	int a = -875;
	unsigned int b = a;
	char temp[100];
	printf("%10d    = %032s = %d\n", a, itoa(a, temp, 2), a);
	printf("%10d>>2 = %032s = %d\n", a, itoa(a>>2, temp, 2), a >> 2);
	printf("%10u    = %032s = %u\n", b, itoa(b, temp, 2), b);		
	printf("%10u>>2 = %032s = %u\n", b, itoa(b >> 2, temp, 2), b >> 2);
	return 0;
} 
