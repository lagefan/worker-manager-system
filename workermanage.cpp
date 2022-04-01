#include<iostream>
using namespace std;
#include"workermanage.h"
#include<fstream>
#define FILENAME "demo.txt"
workmanager::workmanager()//构造函数
{
	//文件不存在的情况
	ifstream ist;
	ist.open(FILENAME, ios::in);
	if (!ist.is_open()) 
	{
		cout << "文件不存在" << endl;
		this->file_isempty = true;
		this->workerarr = NULL;
		this->workerNUM = 0;
		ist.close();
		return;
	}
	//文件存在但没有记录的情况
	char c;
	ist >> c;
	if (ist.eof())//如果c没有读取到内容，则.eof()返回为1
	{
		cout << "文件为空" << endl;
		this->file_isempty = true;
		this->workerarr = NULL;
		this->workerNUM = 0;
		ist.close();
		return;
	}
	//文件存在，并且含有数据
	this->workerNUM = this->get_filenum();
	this->file_isempty = false;
	//创建数组
	this->workerarr = new worker * [this->workerNUM];
	//调用初始化函数
	this->init();
	//测试代码
	/*for (int i = 0; i < this->workerNUM; i++)
	{
		this->workerarr[i]->showinfo();
	}*/
}
workmanager::~workmanager()//析构函数
{
	if (this->workerarr != NULL)
	{
		delete[]this->workerarr;
		this->workerarr = NULL;
	}
}
void workmanager::showmenu()//显示菜单
{
		cout << "欢迎使用职工操作系统" << endl;
		cout << "0 退出管理程序" << endl;
		cout << "1 增加职工信息" << endl;
		cout << "2 显示职工信息" << endl;
		cout << "3 删除离职员工" << endl;
		cout << "4 修改职工信息" << endl;
		cout << "5 查找职工信息" << endl;
		cout << "6 按照编号排序" << endl;
		cout << "7 清空所有文档" << endl;
		cout << endl;
}
void workmanager::exitsystem()//退出程序
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}
void workmanager::worker_add()
{
	cout << "请输入你要添加的职工数" << endl;
	int t_num;
	cin >> t_num;
	int newsize = this->workerNUM + t_num;
	if (t_num <= 0) { cout << "你是个傻逼,程序自动终止" << endl; return; }
	worker**newspace = new worker * [newsize];
	if (this->workerNUM > 0)//循环将数据库中的数据迁移到新的空间中
	{
		for (int i = 0; i < (this->workerNUM); i++)
		{
			newspace[i] = this->workerarr[i];
		}
	}
	for (int j=0; j < t_num; j++)//增加数据
	{
		int i_id;
		string i_name;
		int i_depnum;
		cout << "请输入第" << j + 1 << "位员工编号" << endl;
		cin >> i_id;
		cout << "请输入第" << j + 1 << "位员工姓名" << endl;
		cin >> i_name;
		cout << "请输入第" << j + 1 << "位员工岗位编号" << endl;
		cout << "1 打工人" << endl;
		cout << "2 经理" << endl;
		cout << "3 老板" << endl;
		cin >> i_depnum;
		worker* index=NULL;
		switch (i_depnum)
		{
			case 1:
				index = new employee(i_id, i_name, i_depnum);
				break;
			case 2:
				index = new manager(i_id, i_name, i_depnum);
				break;
			case 3:
				index = new boss(i_id, i_name, i_depnum);
				break;
			default:
				cout << "你是个傻逼" << endl;
				cout << "自动终止" << endl;
				return;
		}
		newspace[this->workerNUM + j] = index;
	}
	cout << "添加成功！" << endl;
	this->workerNUM = newsize;//更新数据库的大小
	delete[] this->workerarr;//释放原有空间
	this->workerarr = newspace;//重新指向
}
void workmanager::save()//将员工数据写入到文件中
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->workerNUM; i++)
	{
		ofs << this->workerarr[i]->w_id << "\t" << this->workerarr[i]->w_name << "\t" << this->workerarr[i]->w_depid << endl;
	}
	ofs.close();
}
int workmanager::get_filenum()//获取文件中员工的个数
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int depnum;
	int num=0;
	while (ifs >> id && ifs >> name && ifs >> depnum)
	{
		num++;
	}
	ifs.close();
	return num;
}
void workmanager::init()//从文件中获取员工数据
{
	ifstream ifs1;
	ifs1.open(FILENAME, ios::in);
	int id;
	string name;
	int depnum;
	int index = 0;
	while (ifs1 >> id && ifs1 >> name && ifs1 >> depnum)
	{
		worker* temp = NULL;
		switch (depnum)
		{
		case 1:
			temp = new employee(id, name, depnum);
			break;
		case 2:
			temp = new employee(id, name, depnum);
			break;
		case 3:
			temp = new employee(id, name, depnum);
			break;
		}
		this->workerarr[index] = temp;
		index++;
	}
	ifs1.close();
}
void workmanager::show_file()//显示员工
{
	if (this->file_isempty == true)
	{
		cout << "数据库中没有数据，请先添加数据" << endl;
	}
	else
	{
		for (int i = 0; i < this->workerNUM; i++)
		{
			this->workerarr[i]->showinfo();
		}
	}
	system("pause");
	system("cls");
}
int workmanager::worker_isexist(int id)
{
	int index = -1;
	for (int i = 0; i < this->workerNUM; i++)
	{
		if (this->workerarr[i]->w_id == id)
		{
			index = i;
			break;
		}
		return index;
	}
}
void workmanager::del_worker()
{
	if (this->file_isempty == true) { cout << "文件为空，没有可操作的数据！" << endl; return; }
	int d_id;
	cout << "请输入您想删除的员工的ID" << endl;
	cin >> d_id;
	if (this->worker_isexist(d_id) != -1)
	{
		for (int i = this->worker_isexist(d_id)-1/*第一次没有想到这样处理*/; i < this->workerNUM; i++)
		{
			this->workerarr[i] = this->workerarr[i + 1];//数据前移实现删除数据
		}
		this->save();//更新数据库
		cout << "delete successfully" << endl;
	}
	else { cout << "该员工不存在" << endl; }
	system("pause");
	system("cls");
}
void workmanager::mod_worker()
{
	if (this->file_isempty == true) { cout << "文件为空，没有可操作的数据！" << endl; return; }
	int d_id;
	cout << "请输入您想修改的员工的ID" << endl;
	cin >> d_id;
	if (this->worker_isexist(d_id) != -1)
	{
		int d_id;
		int id;
		string name;
		int dep_id;
		int temp;
		cout << "请输入你要修改的员工的职工编号" << endl;
		cin >> d_id;
		cout << "请输入你要修改的员工数据" << endl;
		cout << "1 员工编号" << endl;
		cout << "2 员工姓名" << endl;
		cout << "3 员工部门编号" << endl;
		cin >> temp;
		if (temp == 1) 
		{
			cout << "请输入修改后的员工编号" << endl;
			cin >> id;
			this->workerarr[this->worker_isexist(d_id)]->w_id = id;
			this->save();
			cout << "修改成功！" << endl;
		}
		if (temp == 2)
		{
			cout << "请输入修改后的员工姓名" << endl;
			cin >> name;
			this->workerarr[this->worker_isexist(d_id)]->w_name = name;
			this->save();
			cout << "修改成功！" << endl;
		}
		if (temp == 3)
		{
			cout << "请输入你想要修改的员工部门编号" << endl;
			cin >> dep_id;
			worker* index = NULL;
			switch (dep_id)
			{
			case 1:
				index = new employee(this->workerarr[this->worker_isexist(d_id)]->w_id, this->workerarr[this->worker_isexist(d_id)]->w_name,dep_id);
				break;
			case 2:
				index = new manager(this->workerarr[this->worker_isexist(d_id)]->w_id, this->workerarr[this->worker_isexist(d_id)]->w_name, dep_id);
				break;
			case 3:
				index = new boss(this->workerarr[this->worker_isexist(d_id)]->w_id, this->workerarr[this->worker_isexist(d_id)]->w_name, dep_id);
				break;
			default:
				cout << "部门编号不存在！" << endl;
				break;
			}
			this->workerarr[this->worker_isexist(d_id)] = index;
			this->save();
			cout << "修改成功！" << endl;
		}
	}
	else { cout << "该员工不存在" << endl; }
	system("pause");
	system("cls");
}
void workmanager::find_worker()//按照员工ID和姓名两种方式查找
{
	if (this->file_isempty == true) { cout << "文件为空" << endl; return; }
	cout << "请输入你要查找的方式" << endl;
	cout << "1 按照员工ID查找" << endl;
	cout << "2 按照员工姓名查找" << endl;
	int num;
	cin >> num;
	bool flag = false;//关键点：第一次没有想到
	switch (num)
	{
	case 1:
		cout << "请输入你要查找的ID" << endl;
		int d_id;
		cin >> d_id;
		int index = this->worker_isexist(d_id);
		if (index != -1) { this->workerarr[index]->showinfo(); flag = true; }
		break;
	case 2:
	{cout << "请输入你要查找的姓名" << endl;
	string name;
	cin >> name;
	for (int i = 0; i < this->workerNUM; i++)
	{
		if (this->workerarr[i]->w_name == name)
		{
			this->workerarr[i]->showinfo();
			flag = true;
		}
	}
	break; }
	default:
		cout << "请输入正确的数字" << endl;
		break;
	}
	if (flag == true)
	{
		cout << "输出成功！" << endl;
	}
	else { cout << "查无此人" << endl; }
}
void workmanager::clear_file()
{
	cout << "确认清空文件？" << endl;
	cout << "1 确定" << endl;
	cout << "2 返回" << endl;
	int temp;
	cin >> temp;
	if (temp == 1)
	{
		ofstream ofs;
		ofs.open(FILENAME, ios::trunc);//打开模式ios::trunc,如果存在文件删除并重新创建
		ofs.close();
		if (this->workerarr != NULL)
		{
			for (int i = 0; i < this->workerNUM; i++)
			{
				delete this->workerarr[i];
			}
			this->workerNUM = 0;//重置所有参数
			delete[]this->workerarr;
			this->workerarr = NULL;
			this->file_isempty = true;
			cout << "格式化成功！" << endl;
		}
	}
	system("pause");
	system("cls");
}