#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <assert.h>
using namespace std;

//��ͳ�汾String��ʵ��
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


//�ִ��汾��ʵ��
class String
{
public:
	String(const char *str = "")
	{
		if (nullptr == str)
			str = "";//��д��

		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s)
		:_str(nullptr)
	{
		String StrTmp(s._str);
		swap(_str, StrTmp._str);//��д��
	}

	/*String& operator=(const String& s)
	{
		if (this != &s){
			String StrTmp(s);
			swap(_str, StrTmp._str);//��д��
		}
		return *this;
	}*/
	String& operator=(String s)//��д��(�����Ǵ���һ����ʱ����[�����˿������캯��])
	{
		swap(_str, s._str);//��д��
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