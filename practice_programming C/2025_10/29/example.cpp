#include <stdio.h> 

char *my_itoa(int num, char *str) {
	int len = 0, i, temp;
	while(num) {
		str[len++] = num % 10 + '0';
		num /= 10;
	}
	str[len] = 0;
	
	for (i = 0; i < len / 2; i++)
		temp = str[i], str[i] = str[len - i - 1], str[len - i - 1] = temp;
	return str;
}

int main() {
	char a[100];
	my_itoa(9845, a);
	puts(a);
	    
    return 0;
} 
