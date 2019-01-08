#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <assert.h>
using namespace std;

//传统版本String类实现
class String
{
public:
	String(const char *str = "")
	{
		if (nullptr == str){
			assert(str);
			return;
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s)
		:_str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}

	String& operator=(const String& s)
	{
		if (this != &s){
			char *pstr = new char[strlen(s._str) + 1];
			strcpy(pstr, s._str);
			delete[] _str;
			_str = pstr;
		}
		return *this;
	}

	~String()
	{
		if (_str){
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char *_str;
};


//现代版本的实现
class String
{
public:
	String(const char *str = "")
	{
		if (nullptr == str)
			str = "";//新写法

		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s)
		:_str(nullptr)
	{
		String StrTmp(s._str);
		swap(_str, StrTmp._str);//新写法
	}

	/*String& operator=(const String& s)
	{
		if (this != &s){
			String StrTmp(s);
			swap(_str, StrTmp._str);//新写法
		}
		return *this;
	}*/
	String& operator=(String s)//新写法(参数是创建一个临时对象[调用了拷贝构造函数])
	{
		swap(_str, s._str);//新写法
		return *this;
	}

	~String()
	{
		if (_str){
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char *_str;
};

int main()
{
	String s1("hello world!");
	String s2(s1);
	String s3;
	s3 = s1;
	return 0;
}