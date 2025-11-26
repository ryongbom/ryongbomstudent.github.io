// pointer_function_avg_sum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

void avg_sum(float array[], int size, float *a, float *s);

int main()
{
	float a[100], avg, sum;
	int n, i;
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
		scanf_s("%f", &a[i]);
	avg_sum(a, n, &avg, &sum);
	printf("%.2f %.2f\n", avg, sum);
    return 0;
}

/*void avg_sum(float array[], int size, float *a, float *s)
{
	int i;
	float sum = 0;
	for (i = 0; i < size; i++)
	{
		sum += array[i];
	}
	*s = sum;
	*a = sum / size;
	return;
}*/

void avg_sum(float array[], int size, float *avg, float *sum)
{
	int i;
	*sum = 0;
	for (i = 0; i < size; i++)
		*sum += array[i];

	*avg = *sum / size;
	return;
}



