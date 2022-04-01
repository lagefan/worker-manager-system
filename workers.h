#pragma once
#include<iostream>
#include<string>
using namespace std;
class worker
{
public:
	virtual void showinfo() = 0;
	virtual string getname() = 0;
	int w_id;
	string w_name;
	int w_depid;
};
class employee :public worker
{
public:
	employee(int id, string name, int depnum);
	virtual void showinfo();
	virtual string getname();
};
class boss :public worker
{
public:
	boss(int id, string name, int depnum);
	virtual void showinfo();
	virtual string getname();
};
class manager :public worker
{
public:
	manager(int id, string name, int depnum);
	virtual void showinfo();
	virtual string getname();
};