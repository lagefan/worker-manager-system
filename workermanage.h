#pragma once
#include<iostream>
using namespace std;
#include"workers.h"
class workmanager
{
	int workerNUM;
	worker** workerarr;
	bool file_isempty;//如果文件为空，则不必要修改显示文件
	
public:
	workmanager();
	~workmanager();
	void showmenu();//显示菜单
	void exitsystem();//退出系统
	void worker_add();//添加员工
	void save();//写文件
	int get_filenum();//从文件中获取员工个数，便于后续使用
	void init();//初始化数组
	void show_file();//显示员工数据
	int worker_isexist(int id);//根据输入的员工编号判断员工是否存在，如果存在返回位置，不存在返回-1;
	void del_worker();//根据提供的员工ID来删除员工
	void mod_worker();//根据员工ID来修改员工信息
	void find_worker();//根据员工ID和员工姓名来查询信息
	void clear_file();//清空文件
};
