#include <iostream>
using namespace std;

int main()
{
	int i, j;
	for (i = 1, j = 1; j <= 9; i++)
	{
		for (j = 1; j <= i; j++)
		{
			cout << j << "*" << i << "=" << i * j << "\t";
		}
		cout << endl;
	}
	return 0;

