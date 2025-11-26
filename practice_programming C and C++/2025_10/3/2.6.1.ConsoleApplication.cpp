// 2.6.1.ConsoleApplication.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
/*#include <iostream>
using namespace std;


int main()
{
	int n, i, count; //temp;

	cin >> n;
	
	cout << n << "=";

	i = 2;
	count = 0;
	//temp = n;
	//while (i <= n / 2) {
	while (1) {
		//if (temp % i == 0) {
		if (n % i == 0) {
			//temp = temp / i;
			n = n / i;
			count++;
			//if (temp % i != 0 && count == 1) {
			if (n % i != 0 && count == 1){
				//if (temp != 1)
				if (n != 1)
					cout << i << "*";
				else
					cout << i;
			}
			//else if (temp % i != 0 && count > 1) {
			else if (n % i != 0 && count > 1) {
				//if (temp != 1)
				if (n != 1)
					cout << i << "^" << count << "*";
				else
					cout << i << "^" << count;
			}
			continue;
		}
		else {
			count = 0;
			i++;
		}
	}
	cout << endl;
	
    return 0;
}*/

#include <stdio.h>

int main() {
	int n;
	int i, count;

	scanf_s("%d", &n);

	printf("%d=", n);

	i = 2;
	count = 0;
	while (1) {
		if (n % i == 0) {
			n /= i;
			count++;
		}

		else {
			if (count >= 1) {
				if (count > 1)
					printf("%d^%d", i, count);
				else
					printf("%d", i);
				count = 0;

				if (n != 1)
					printf("*");
				else
					break;
			}
			i++;
		}
	}

	return 0;
}
