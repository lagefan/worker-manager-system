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
	cout << "ְ����ţ�" << this->w_id << "\tְ��������" << this->w_name << "\t��λ��" << this->getname () << "\t����ְ��" << "��ɾ�����������";
	cout << endl;
}
string employee::getname()
{
	return string("Ա��");
}

boss::boss(int id, string name, int depnum)
{
	this->w_id = id;
	this->w_name = name;
	this->w_depid = depnum;
}
void boss::showinfo()
{
	cout << "ְ����ţ�" << this->w_id << "\tְ��������" << this->w_name << "\t��λ��" << this->getname() << "\t����ְ��" <<"���ڰ칫����˯���";
	cout << endl;
}
string boss::getname()
{
	return string("�ϰ�");
}

manager::manager(int id, string name, int depnum)
{
	this->w_id = id;
	this->w_name = name;
	this->w_depid = depnum;
}
void manager::showinfo()
{
	cout << "ְ����ţ�" << this->w_id << "\tְ��������" << this->w_name << "��λ��" << this->getname() << "\t����ְ��" << "��Ա����������";
	cout << endl;
}
string manager::getname()
{
	return string("����");
}