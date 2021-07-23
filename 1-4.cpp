#include <iostream>
#include <ctime>        //time
#include <cstdlib>      // rand
using namespace std;

int main()
{
	double gus,num,times=0;
	num = rand() % 100;

	do
	{
		cout << "Guess the number!" << endl;
		cin >> gus;
		if (gus > num)
			cout << "Your guess is bigger than the truth.Try again.\n";
		if (gus < num)
			cout << "Your guess is smaller than the truth.Try again.\n";
		times++;
	} while (gus!=num);
		cout << "Congratulate!\n";
		cout << "Your guess times are\t" << times<<endl;
	return 0;
}
