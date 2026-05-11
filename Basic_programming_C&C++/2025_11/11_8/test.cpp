#include <stdio.h>
#include <stdlib.h>

//int main() {
//	int a = 8;
//	char temp[100];
//	int p = ~a;
//	printf("%d\n", p);
//	printf("%032s", itoa(p, temp, 2));
//	
//	return 0;
//}

int main() {
	int i = 8; 
	int j = 9;
	printf("%d", i >> 1 + j >> 1);
	return 0;
}
