#include <iostream>
using namespace std;

class Base1
{
public:
	Base1();
	~Base1();

private:
	string m_b1;
};
Base1::Base1()
{
	cout << "Constructing Base1" << endl;
}
Base1::~Base1()
{
	cout << "Destructing Base1" << endl;
}
class Base2
{
public:
	Base2();
	~Base2();
private:
	string m_b2;
};
Base2::Base2()
{
	cout << "Constructing Base2" << endl;
}
Base2::~Base2()
{
	cout << "Destructing Base2" << endl;
}

class Base3
{
public:
	Base3();
	~Base3();
private:
	string m_b3;
};
Base3::Base3()
{
	cout << "Constructing Base3" << endl;
}
Base3::~Base3()
{
	cout << "Destructing Base3" << endl;
}

class Component :public Base3
{
public:
	Component()
	{
		cout << "Constructing Component" << endl;
	};
	~Component()
	{
		cout << "Destructing Base3" << endl;
	};
};

class Derived :public Base1, public Base2, public Base3
{
public:
	Derived() {
		cout << "Constructing Derived" << endl;
	}
	~Derived() {
		cout << "Destructing Derived" << endl;
	}
private:
	Component m_c;
};



int main()
{
	Derived d;
	return 0;
}
