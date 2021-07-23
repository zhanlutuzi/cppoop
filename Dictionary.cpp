#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<cstdlib>
using namespace std;



int main()
{
	string words[8000];
	string chinese[8000];
	string w_class[8000];
	int num = 0;
	ifstream infile;
	ifstream in("Dictionary.txt");

	if (!infile)       //测试是否成功打开
	{
		cerr << "open error!" << endl;
		exit(1);
	}
	for (num = 0; num < 8000; num++)
	{
		in >> words[num] >> chinese[num] >> w_class[num];
	}
	string word;
	char command = 'C';
	for (; command != 'E';)
	{
		if (command == 'C')
		{
			cout << "Please input the word you want to search:" << endl;
			cin >> word;
			for (int i = 0; i < 8000; i++)
			{
				string search = words[i];
				if (search == word)
				{
					cout << chinese[i] << " " << w_class[i] << endl;
					break;
				}
			}
			cout << "C__Continue" << endl;
			cout << "E__End" << endl;
			cout << "Please input your command:" << endl;
			cin >> command;
		}
		else if (command == 'E')
		{
			break;
		}
		else
		{
			cout << "Wrong command" << endl;
		}
	}
	cout << "Goodbye!" << endl;
	return 0;
}

