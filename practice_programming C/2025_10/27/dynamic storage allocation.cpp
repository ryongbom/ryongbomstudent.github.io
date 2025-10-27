// dynamic storage allocation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int main()
{
	int n, i, j;
	float *score, temp;
	
	scanf_s("%d", &n);
	score = (float*)malloc(n * sizeof(float));

	assert(score != NULL);
	for (i = 0; i < n; i++)
		scanf_s("%f", &score[i]);

	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (score[i] < score[j])
			{
				temp = score[i];
				score[i] = score[j];
				score[j] = temp;
			}
		}
	}

	for (i = 0; i < n; i++)
		printf("%0.2f ", score[i]);
	free(score);
    return 0;
}

