
#include "person.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

CPerson::CPerson()
{
}

CPerson::CPerson(const char * pname, int age, int s)
{
	name = (char *)malloc(NAME_LEN);
	this->setName(pname);
	strcpy(name, pname);
	this->age = age;
	//this == &cper
	sex = s;
	printf("CPerson call\n");
}

CPerson::~CPerson()
{
	free(name);
	printf("~~~~CPerson call\n");
}

char * CPerson::getName()
{
	return name;
}
void CPerson::setName(const char * name)
{
	strcpy(this->name, name);
}

int CPerson::getAge() const
{
	age++;
	return age;
}
void CPerson::setAge(int a)
{
	if (a < 0 || a > 150)
	{
		printf("age error\n");
		return;
	}
	age = a;
}

void CPerson::setAge(int a, int b)
{
	age = a + b;
}

char CPerson::getSex()
{
	return sex;
}