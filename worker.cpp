#include<iostream>
#include"workers.h"
#include<string>
using namespace std;
employee::employee(int id,string name,int depnum)
{
	this->w_id = id;
	this->w_name = name;
	this->w_depid = depnum;
}
void employee::showinfo()
{
	cout << "职工编号：" << this->w_id << "\t职工姓名：" << this->w_name << "\t岗位：" << this->getname () << "\t部门职责：" << "完成经理交给的任务";
	cout << endl;
}
string employee::getname()
{
	return string("员工");
}

boss::boss(int id, string name, int depnum)
{
	this->w_id = id;
	this->w_name = name;
	this->w_depid = depnum;
}
void boss::showinfo()
{
	cout << "职工编号：" << this->w_id << "\t职工姓名：" << this->w_name << "\t岗位：" << this->getname() << "\t部门职责：" <<"坐在办公室内睡大觉";
	cout << endl;
}
string boss::getname()
{
	return string("老板");
}

manager::manager(int id, string name, int depnum)
{
	this->w_id = id;
	this->w_name = name;
	this->w_depid = depnum;
}
void manager::showinfo()
{
	cout << "职工编号：" << this->w_id << "\t职工姓名：" << this->w_name << "岗位：" << this->getname() << "\t部门职责：" << "给员工发布任务";
	cout << endl;
}
string manager::getname()
{
	return string("经理");
}