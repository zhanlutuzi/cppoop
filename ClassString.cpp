# define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream> 
#include <cstring> 
 using namespace std; 
 class String { public: 
 	friend ostream& operator<<(ostream& os, const String& s); 
 
 	// 默认构造函数 
 	String(const char *str = nullptr); 
 	// 拷贝构造函数 
 	String(const String &str); 
 	// 析构函数 
 	~String(); 
 	// 字符串赋值函数 
 	String& operator=(const String &str); 
 	//字符串相加函数 
 	String& operator+(const String &str); private: 
 char *m_data;  int m_size; 
}; ostream& operator<<(ostream& os, const String& s) 
{  	os << s.m_data;  	return os; 
} 
// 构造函数 
String::String(const char *str) 
{ 
 	if (str == nullptr)  // 对m_data加NULL 判断 
 	{ 
 	 	m_data = new char[1];   // 对空字符串自动申请存放结束标志'\0'的  	 	m_data[0] = '\0';  	 	m_size = 0; 
 	} 
 	else 
 	{ 
 	 	m_size = strlen(str);  	 	m_data = new char[m_size + 1];  	 	strcpy(m_data, str);//C 库函数 - strcpy()    
 	 	 	 	 	 	 	//传入两个指针  char *strcpy(char *dest, const char *src) 
 
 	} 
} 
 
// 拷贝构造函数 
String::String(const String &str)   //输入参数为const型 
{  	m_size = str.m_size;  	m_data = new char[m_size + 1];  //对m_data加NULL 判断  	strcpy(m_data, str.m_data); 
} 
 
// 析构函数 
String::~String() 
{  	delete[] m_data; 
} 
 
// 字符串赋值函数 
String& String::operator=(const String &str)  // 输入参数为const 
{ 
 	if (this == &str)    //检查自赋值  	 	return *this; 
 
 	delete[] m_data;    //释放原有的内存资源 
 	m_size = strlen(str.m_data);    //c库 strlen 函数  	m_data = new char[m_size + 1];  //对m_data加NULL 判断  	strcpy(m_data, str.m_data);  	return *this;       //返回本对象的引用 
}  int main() 
{ 
 	String str1("abc");  	String str2("123");  	cout << "Test Begin..........\n";  	cout << "Create a object str1,give it abc\n";  	cout << "str1= ";  	cout << str1<<endl;  	cout << "Create a object str2,give it 123\n";  	cout << "str2= ";  	cout << str2<<endl;  	cout << "replace str1 as str2  str2=str1\n";  	str2 = str1;  	cout << "Here is the new str2\n";  	cout << str2<<endl;  	return 0; 
} 
