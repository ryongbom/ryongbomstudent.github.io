// function_swap_sort_pointArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

void sort(int *array, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		int temp = 0;
		for (j = i + 1; j < n; j++)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
	return;
}

int main()
{
	int i, n;
	int arr[100];
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	sort(arr, n);
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}

    return 0;
}

