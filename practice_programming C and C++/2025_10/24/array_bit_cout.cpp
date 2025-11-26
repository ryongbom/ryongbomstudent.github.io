#include <stdio.h>

int n;
int a[100];

void func(int step)
{
	if (step == n)
	{
		for (int i = 0; i < n; i++)
		{
			printf("%d", a[i]);
		}
		printf("\n");
		return;
	}
	
	a[step]= 0;
	func(step + 1);
	a[step] = 1;
	func(step + 1);
}

int main(){
	scanf("%d", &n);
	func(0);
	return 0;
}
