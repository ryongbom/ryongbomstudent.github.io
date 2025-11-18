#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
int main()
{
	int i, n, j = 1, A, B;
	cin >> n >> A >> B;
	int M[100], C[100];
	srand(time(NULL));
	for(i = 0; i < n; i++)
	{
		M[i] = rand() % 10 - 5;
	}
	for (i = 0; i < n; i++)
		cout << "M[" << i << "]=" << M[i] << ", ";
	cout << endl; 
	for (i = 0; i < n; i++)
	{
		if (M[i] >= A && M[i] <= B)
		{
			C[j++] = M[i];
		}
	}
	C[0] = 0;
	for (i = 0; i < j; i++)
	{
		cout << "C[" << i << "]=" << C[i] << ",";
	}
	cout << endl;
	int k;
	for (i = 0; i < j; i++)
		for (k = i + 1; k < j; k++)
			if(C[i] < C[k])
				swap(C[i], C[k]);
	for (i = 0; i < j; i++)
		cout << "C[" << i << "]=" << C[i] << ", ";
	return 0;
 } 
