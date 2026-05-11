// function_practice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int getRandomNumber(int level);
void putProblem(int level, int num1, int num2);
void success();
void fail();

int main(void)
{
	cout << ">>>>>    GAME START !!!" << endl << endl << endl;
	
	int count = 0;
	int f = 0;

	srand(time(NULL));
	for (int i = 1; i <= 10; i++)
	{
		int num1 = getRandomNumber(i);
		int num2 = getRandomNumber(i);
		putProblem(i, num1, num2);

		int answer;
		cin >> answer;

		if (answer == num1 * num2)
		{
			success();
			count++;
		}
		else
		{
			fail();
			f++;
		}
	}
  
	cout << "Result: " << count << " true " << f << " false" << endl << endl;
	cout << "GAME END !!!   >>>>>" << endl << endl << endl;
	return 0;
}


void success()
{
	cout << endl << "     TRUE!!!" << endl << endl;
}

void fail()
{
	cout << endl << "     FALSE!!!" << endl << endl;
}

int getRandomNumber(int level)
{
	return rand() % (level * 10) + 1;
}

void putProblem(int level, int num1, int num2)
{
	cout << "<<   " << level << " level" << "   >>" << endl << endl;
	cout << num1 << " * " << num2 << " = ";
}