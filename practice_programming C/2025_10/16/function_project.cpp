// function_project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getRandomNumber(int level);
void showQuestion(int level, int num1, int num2 );
void success();
void fail();

int main(void)
{
	srand(time(NULL));
	int count = 0;
	for (int i = 1; i <= 5; i++)
	{
		int num1 = getRandomNumber(i);
		int num2 = getRandomNumber(i);
		showQuestion(i, num1, num2);

		int answer = -1;
		scanf_s("%d", &answer);
		if (answer == -1)
		{
			printf("end programm\n");
			exit(0);
		}
		else if(answer == num1 * num2)
		{
			success();
			count++;
		}
		else
		{
			fail();
		}
	}

	printf("\n\nyou pass %d passwords\n", count);

    return 0;
}

int getRandomNumber(int level)
{
	return rand() % (level * 7) + 1;
}

void showQuestion(int level, int num1, int num2)
{
	printf("\n\n\n########## %d password ##########\n", level);
	printf("\n\t%d * %d ?\n\n", num1, num2);
	printf("#################################\n");
	printf("\npassword (end : -1) >> ");
}

void success()
{
	printf("\n >> That's very good!");
}

void fail()
{
	printf("\n >> false!");
}