//#pragma once

#ifndef __TEST__
#define __TEST__
#define NAME_LEN 64

class CPerson
{
public:
	CPerson();
	CPerson(const char * pname, int age, int s);
	~CPerson();

	char * getName();
	void setName(const char * name);
	int getAge() const;
	void setAge(int a = 22);
	void setAge(int a, int b);
	char getSex();
private:
	char * name;
	mutable int  age;
	char sex;
};

#endif