#include <iostream>
#include <string>

using namespace std;

class Animal
{
public:
	Animal() {};
	Animal(const string &a);
private:
	string m_strName;
};

Animal::Animal(const string &a)
{
	this->m_strName = a;
}
class Reptile :virtual public Animal
{
public:
	Reptile() {};
	Reptile(const string&) { Animal(); }
	void run() {};
};
class Aquatic :virtual public Animal
{
public:
	Aquatic() {};
	void run() {};
	Aquatic(const string&) { Animal(); }
};

class Fork :public Reptile, public Aquatic
{
public:
	Fork(const string &) { Animal(); }
};

int main()
{
	return 0;
}
