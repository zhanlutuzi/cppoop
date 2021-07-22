//Opr.h
#pragma once
#include<iostream>
#include<cmath>
#include<iomanip>
#include<string>

void Add(int a, float s[]);						//Add a score 添加一个成绩
void Del(int a, float s[]);						//Del a score  删除一个成绩
void List(int a, float s[]);						//List All scores and count 列出所有成绩
void Min(int a, float s[]);						// Minimum of scores 成绩最小值及索引
float Average(int a, float s[]);						//Average of scores    成绩均值
void Max(int a, float s[]);						//Maximum of scores  成绩最大值及索引
void Std(int a, float s[]);						//Standard derivation of scores 成绩标准方差

											//S - Save scores to file 保存成绩到文件(选做）
											//O - Open scores from file 从文件加载成绩（选做）

void X();								//Exit 退出程序

//Opr.cpp
#include<iostream>
#include "opr.h"
using namespace std;

void Add(int a, float s[])
{
	float b;
	cin >> b;
	s[a] = b;
}

void Del(int a, float s[])
{
	cout << "which num you want to del?" << endl;
	float b;
	int d = 0;
	cin >> b;
	for (int i = 0; i < a; i++) {
		if (b == s[i]) { d = i; };
	}
	for (int i = d; i < a; i++) {
		s[i] = s[i + 1];
	}
}

void List(int a, float s[]) {
	for (int i = 0; i < a; i++) {
		cout << s[i] << endl;
	}
}

void Min(int a, float s[]) {
	float min = s[0];
	for (int i = 0; i < a; i++) {
		if (min > s[i]) { min = s[i]; }
	}
	cout << min << endl;
}

float Average(int a, float s[]) {
	float sum = 0, aver = 1;
	for (int i = 0; i < a; i++) {
		sum += s[i];
	}
	aver = sum / a;
	return aver;
}

void Max(int a, float s[]) {
	float max = s[0];
	for (int i = 0; i < a; i++) {
		if (max < s[i]) { max = s[i]; }
	}
	cout << max << endl;
}
void Std(int a, float s[]) {
	float b = Average(a, s);
	double c = 0, d = 0, e = 0;
	for (int i = 0; i < a; i++) {
		c += (b - s[i])*(b - s[i]);
	}
	d = c / a;
	e = sqrt(d);
	cout << "标准方差为： " << e << endl;
}
void X() { cout << "Quit." << endl; }


//Main.cpp
#include<iostream>
#include<cmath>
#include<iomanip>
#include<string>
#include"opr.h"
using namespace std;

int main() {
	static int n;
	static float s[] = { 0 };
	int b;
	char c;
	float d;

	cout << "srudents num:" << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "scores:" << endl;
		cin >> d;
		s[i] = d;
	}
	cout << "Enter a key:" << endl;
	cout << "A-Add a score		  D-delete a score " << endl
		<< "L-list all scores	  M-the min of scores" << endl
		<< "P-the max of scores   N-the average of scores" << endl
		<< "T-standard of scores  X-Quit" << endl;


	do {
		cout << "input a key:";
		cin >> c;
		if (c == 'A') {
			Add(n, s);
			n += 1;
		}
		else if (c == 'D') {
			Del(n, s);
			n -= 1;
		}
		else if (c == 'L') {
			List(n, s);
		}
		else if (c == 'M') {
			Min(n, s);
		}
		else if (c == 'N') {
			cout << Average(n, s) << endl;
		}
		else if (c == 'P') {
			Max(n, s);
		}
		else if (c == 'T') {
			Std(n, s);
		}
		else if (c == 'X') {
			X();
			break;
		}
		else
			cout << "Enter The Right Key!" << endl;
	} while (c != 'X');
	return 0;
}

