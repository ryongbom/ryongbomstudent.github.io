// 2.function_c.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

void function_with_params(int num1, int num2, int num3);
int apple(int total, int ate);

int main(void)
{
	//function_with_params(34, 56, 88);
	//int ret = apple(10, 3);
	//printf("you have only %d apples\n", ret);
	printf("you have only %d apples\n", apple(10, 3));
    return 0;
}

void function_with_params(int num1, int num2, int num3)
{
	printf("num1 = %d, num2 = %d, num3 = %d\n", num1, num2, num3); 
}

int apple(int total, int ate)
{
	return total - ate;
}