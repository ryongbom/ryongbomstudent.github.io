#include <iostream>
using namespace std;

void error(char *errstr, int ind, int upp)
{
	cout << errstr << ind << "th of " << upp << " elements" << endl;
}

void error(char *errstr)
{
	cout << errstr << endl;
}

void error(char *errstr, char c)
{
	cout << errstr << ' ' << c << endl;
}

int main () {
	int index = 10; 
  int upperBound = 5; 
  char selectVal = 'A'; 
  error("Array out of bounds:", index, upperBound); 
  error("Division by zero"); 
  error("Invalid selection", selectVal); 
  return 0;
}
