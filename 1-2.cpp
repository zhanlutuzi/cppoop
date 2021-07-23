#include <iostream>
using namespace std;

int main()
{
	double k, a, b;
	char c='0';
	cout << "输入0以结束程序，输入其他以继续" << endl;
	cin >> k;
	while (k != 0)
	{
		cout << "请输入第一个数a" << endl;
		cin >> a;
		cout << "请输入操作" << endl;
		cin >> c;
		cout << "请输入第二个数b" << endl;
		cin >> b;
		break;
	}
	if (c == '+')
		cout << a << "+" << b << "=" << a + b << endl;
	if (c == '-')
		cout << a << "-" << b << "=" << a - b << endl;
	if (c == '*')
		cout << a << "*" << b << "=" << a * b << endl;
	if (c == '/')
		cout << a << "/" << b << "=" << a / b << endl;
	return 0;
}
