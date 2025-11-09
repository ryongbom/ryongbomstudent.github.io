#include <stdio.h>
#include <stdlib.h>

#define football 0
#define swim 1
#define music 2
#define art 3
#define basketball 4

int main() {
	int hobby;
	char temp[100];
		
	hobby = 0;
	printf("%032s\n", itoa(hobby, temp, 2));
	hobby = hobby | 1 << music;
	printf("%032s\n", itoa(hobby, temp, 2));
	return 0;
}
