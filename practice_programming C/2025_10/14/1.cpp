// 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{
	int i;
	srand(time(NULL));
	for (i = 0; i < 10; i++) {
		printf("%d ", rand() % 10);
	}
	printf("\n");
    return 0;
}*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) 
{
	srand(time(NULL));
	int num = rand() % 100 + 1;
	printf("%d\n", num);

	int answer = 0;
	int chance = 5;
	while (chance > 0) 
	{
		printf("you have %d chance\n", chance--);
		printf("Do you know what is number : ");
		scanf_s("%d", &answer);

		if(answer > num)
		{
			printf("DOWN  !\n");
		}
		else if (answer < num)
		{
			printf("UP  !\n");
		}
		else if (answer == num)
		{
			printf("true !!!\n");
			break;
		}
	}
	
	if (!chance)
		printf("you not found number !!!\n");

	return 0;
}
