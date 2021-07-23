#include <iostream>
#include <string>
using namespace std;

class Person {
public:
	Person() {};
	Person(const string&a);
	string Get_name() 
	{
		return m_strName;
	}
	friend ostream& operator<<(ostream&, const Person&);
	friend istream& operator>>(istream&, Person&);
private:
	string m_strName;
};
ostream& operator<<(ostream &out, const Person&c)
{
	out << c.m_strName;
	return out;
}
istream& operator>>(istream&in, Person&c)
{
	in >> c.m_strName;
	return in;
}

Person::Person(const string &name)
{
	this->m_strName = name;
}
class Student:public Person{
public:

	Student(const string& name,string ID) :Person(name) { m_strSID = ID; m_nLastID++; };
	~Student() { m_nLastID--; };
	friend ostream& operator<<(ostream&, const Student&);
	friend istream& operator>>(istream&, Student&);
	static int GetNum() {
		return m_nLastID;
	}
private:
	string m_strSID;
	static int m_nLastID;
};
int Student::m_nLastID = 0;
ostream& operator<<(ostream&out, const Student&ID)
{
	out <<"ID:" << ID.m_strSID<<endl;
	return out;
}
istream& operator>>(istream&in, Student&ID)
{
	in >> ID.m_strSID;
	return in;
}
int main()
{
	string n1 = "Mary";
	string n2 = "20201";
	string n3 = "Tim";
	string n4 = "20202";
	cout << "Input Student 1's ID" << endl;
	Student s1(n1, n2);
	cin >> s1;
	cout << "Student 1's ID is:" << endl;
	cout << s1;
	cout << "the student number is : ";
	cout << Student::GetNum() << endl;
	cout << "--------------------\n\n";
	cout << "Input Student 2's ID" << endl;
	Student s2(n3, n4);
	cin >> s2;
	cout << "Student 2's ID is :" << endl;
	cout << s2;
	cout << "the student number is : ";
	cout << Student::GetNum() << endl;
	cout << "Ending................" << endl;
	return 0;
}
