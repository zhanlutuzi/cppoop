//Calculator.cpp
#include <iostream>
#include"operate.h"
#include<cmath>
#include <string>
#include <sstream>
using namespace std;


int calculate(int a, int b,char ope)
{
	int res;
	switch (ope)
	{
	case'+':res = add(a, b); break;
	case'-':res = subtract(a, b); break;
	case'*':res = multiply(a, b); break;
	case'/':res = divide(a, b); break;
	case'^':res = pow(a, b); break;
	default:
		throw (invalid_argument("invalidate operator")); break;
	}
	return res;
}


int Result (const string& strexp)
{
	istringstream  iss;
	iss.str(strexp);

	int a, b;
	char oper;
	iss >> a >> oper >> b;
	try
	{
		a = calculate(a, b, oper);
		while (iss.good() && !iss.eof())
		{
			iss >> oper;
			iss >> b;

			a = calculate(a, b, oper);
		}
	}
	catch (std::exception& e)
	{
		cerr << e.what() << endl;
	}

	return a;
}

int main()
{
	string mycal;
	cin >> mycal;
	cout << Result(mycal) << endl;
	return 0;
}

//Operate.h
#pragma once
int add (int a, int b);
int subtract(int a, int b);
int multiply (int a, int b);
int divide (int a, int b);
int factorial(int a);

//Operate.cpp
int add(int a, int b)
{
	int c;
	c = a + b;
	return c;
}

int subtract(int a, int b)
{
	int c;
	c = a - b;
	return c;
}

int multiply(int a, int b)
{
	int c;
	c = a * b;
	return c;
}

int divide(int a, int b)
{
	int c;
	c = a / b;
	return c;

}

int factorial(int a)
{
	if (a == 1)
	{
		return 1;
	}
	else
	{
		return  a*factorial(a - 1);
	}
}

