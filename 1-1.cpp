#include <iostream>
using namespace std;

int main()
{
	int mylong = 0;
	cout << "请输入菱形的边长" << endl;
	cin >> mylong;
	cout << "图形如下" << endl;

	//上半部分

	for (int i = 0; i < mylong; i++)  //分别打印每一行
	{
		for (int j = 0; j < (mylong - 1) - i; j++)//刚好保证在打印最长的一行时无空格
		{
			cout << " ";
		}

		for (int j = 0; j < (2 * i + 1); j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	//下半部分
	for (int i = 0; i < mylong; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			cout << " ";
		}
		for (int j = 0; j < 2 * (mylong - 1) - (1 + 2 * i); j++)
		{
			cout << "*";
		}
		cout << endl;

	}
	return 0;
}
