//Calendar.h
void printMonth(int year, int month);
void printMonthTitle(int year, int month);
void printMonthBody(int year, int month);
int getStartDay(int year, int month);
int getTotalNumberOfDays(int year, int month);
int getNumberOfDaysInMonth(int year, int month);
bool isLeapYear(int year);

//Calendar.cpp
#include<iostream>
#include<iomanip>
#include"Calendar.h"
using namespace std;
void printMonthTitle(int year, int month)
{
	char chMonth[12][7] = { "一月","二月","三月","四月","五月","六月","七月","八月","九月","十月","十一月","十二月" };
	cout << endl;
	cout << setw(12) << year << "年" << "    ";
	cout << chMonth[month - 1] << endl;
	cout << "------------------------------" << endl;
	cout << "  Sun Mon Tue Wed Thu Fri Sat" << endl;
}

void printMonthBody(int year, int month)
{
	int startDay = getStartDay(year, month);
	int numberOfDaysInMonth = getNumberOfDaysInMonth(year, month);
	int i = 0;
	for (i = 0; i < startDay; i++)
	{
		cout << "    ";
	}
	for (i = 1; i <= numberOfDaysInMonth; i++)
	{
		cout << setw(4) << i;
		if ((i + startDay) % 7 == 0)
		{
			cout << endl;
		}
	}
	cout << endl;
	cout << "------------------------------" << endl;
}

int getStartDay(int year, int month)
{
	int startDay1800 = 3;
	int totalNumberOfDays = getTotalNumberOfDays(year, month);
	return (totalNumberOfDays + startDay1800) % 7;
}

int getTotalNumberOfDays(int year, int month)
{
	int total = 0;
	for (int i = 1800; i < year; i++)
	{
		if (isLeapYear(i))
		{
			total = total + 366;
		}
		else
		{
			total = total + 365;
		}
	}
	for (int i = 1; i < month; i++)
	{
		total = total + getNumberOfDaysInMonth(year, i);
	}
	return total;
}

int getNumberOfDaysInMonth(int year, int month)
{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		return 31;
	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		return 30;
	}
	if (month == 2)
	{
		return isLeapYear(year) ? 29 : 28;
	}
	return 0;
}

bool isLeapYear(int year)
{
	return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

//Main.cpp
#include<iostream>
#include<iomanip>
#include"Calendar.h"
using namespace std;
int main()
{
	cout << "请输入年份（如2018）:";
	int year;
	cin >> year;
	cout << "请输入月份（1-12）:";
	int month;
	cin >> month;
	printMonth(year, month);
	return 0;
}
void printMonth(int year, int month)
{
	printMonthTitle(year, month);
	printMonthBody(year, month);
}
 

