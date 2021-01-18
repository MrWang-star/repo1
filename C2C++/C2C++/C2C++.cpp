// C2C++.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "person.h"
#include <iostream>
using namespace std;
#include "point.h"
#include "lisi.h"
#include "zhangsan.h"
using namespace zhangsan;

int var = 111;

int add(int a, int b, int c = 10)
{
	return a + b + c;
}

int func1(int * pn)
{
	int i = 0;
	(*pn)++;
	return 0;
}

int func1(int & n)
{
	n++;
	return 0;
}

struct Person
{
	char name[NAME_LEN];
	int age;
};

int main()
{
	struct Person per = {"alice", 25};
	strcpy_s(per.name, "spark.hao");
	per.age = 30;
	Person per1 = { "alice", 25 };
	
	//创建对象时会调用构造函数，构造函数可以 重载
	CPerson cper("aaabbb", 26, 'w'), * pper; 
	pper = &cper;
	cper.setName("spark.hao");

	//类的成员函数重载
	cper.setAge();
	cper.setAge( 20, 50);

	printf("person info: name %s, age %d\n", cper.getName(), cper.getAge(), cper.getSex());

	//整型变量的引用
	int a = 10;
	int & b = a;
	int & c(b);
	c = 20;
	int *pn = &a;
	pn = &b;

	//引用参数和指针参数
	func1(&a);	
	func1(a);

	//类对象的引用
	Person per11;
	Person & per12 = per11;
	Person * pper1 = &per11;

	printf("sizeof(per12) = %d, sizeof(pper1) = %d\n", sizeof(per12) , sizeof(pper1));

	//malloc和new分配内存
	char * parr1 = (char *)malloc(NAME_LEN);
	char * parr2 = new char[NAME_LEN];

	memset(parr1, 0 , NAME_LEN * sizeof(char));
	strcpy(parr1, "abcdefg");

	memset(parr2, 0, NAME_LEN * sizeof(char));
	strcpy(parr2, "123456789");

	free(parr1);
	delete []parr2;

	//用new为对象分配内存
	CPerson * pper3 = new CPerson("bbb", 23, 'm');

	delete pper3;

	cout << "name " << cper.getName() <<", age "<< cper.getAge() << endl;

	//cin >> a;
	//cout << "a = " << a << endl;

	CPoint po1(1, 2);

	int var = 222;
	var = 333;

	::var = 444;

	lisi::global_var = 111;

	global_var = 222;

	//在释放cper对象时会以调用 析构函数
	return 0;
}
