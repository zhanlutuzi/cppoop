#include <iostream>
#include <string>

using namespace std;

class Animal
{
public:
	Animal() {};
	Animal(const string &a);
	string getname()
	{
		return m_strName;
	}
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
	Reptile(const string&b) :Animal(b) { ; }
	void run() { cout << this->getname()<<" has run!\n"; };
};
class Aquatic :virtual public Animal
{
public:
	Aquatic() {};
	void run() { cout << this->getname() << " has run!\n"; };
	Aquatic(const string&c):Animal(c) { ; }
};

class Fork :public Reptile, public Aquatic
{
public:
	Fork(const string &d):Animal(d) { ; }
};

int main()
{
	Animal A1("Animal1");
	Reptile R1("Reputile1");
	R1.run();
	Aquatic Aq1("Aquatic1");
	Aq1.run();
	Fork F1("Fork1");
	return 0;
}
