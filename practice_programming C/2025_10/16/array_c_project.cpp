// array_c_project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	srand(time(NULL));
	printf("\n\n >> Game start !!!\n\n");
	int answer;
	int treatment = rand() % 4;

	int cntShowBottle = 0;
	int prevCntShowBottle = 0;

	for (int i = 1; i <= 3; i++)
	{
		int bottle[4] = { 0, 0, 0, 0 };
		do {
			cntShowBottle = rand() % 2 + 2;
			prevCntShowBottle = rand() % 2 + 2;
		} while (cntShowBottle == prevCntShowBottle);
		prevCntShowBottle = cntShowBottle;

		int isIncluded = 0;
		printf(" > %d try : ", i);

		for (int j = 0; j < cntShowBottle; j++)
		{
			int randBottle = rand() % 4;

			if (bottle[randBottle] == 0)
			{
				bottle[randBottle] = 1;
				if (randBottle == treatment)
				{
					isIncluded = 1;
				}
			}

			else
			{
				j--;
			}
		}

		for (int k = 0; k < 4; k++)
		{
			if (bottle[k] == 1)
				printf("%d ", k++);
		}
		printf("touch\n\n");

		if (isIncluded == 1)
		{
			printf(" >> Success ! \n");
		}
		else
		{
			printf(" >> False ! \n");
		}

		printf("\n\n .... click here ...\n");
	}

	printf("\n\nwhat number do you think? ");
	scanf_s("%d", &answer);

	if (answer == treatment + 1)
	{
		printf("\n >> TURE!!!\n");
	}
	else
	{
		printf("\n >> FALSE!!! \n");
	}

	return 0;
}


