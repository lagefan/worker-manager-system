#include<iostream>
using namespace std;
#include"workers.h"
#include<string>
#include"workermanage.h"
int main()
{
	workmanager test;
	test.showmenu();
	cout << "请输入您要进行的操作" << endl;
	int operatornum;
	cin >> operatornum;
	switch (operatornum)
	{
	case 0:
		test.save();
		test.exitsystem();
		break;//退出管理系统 *
	case 1:
		test.worker_add();
		break;//增加职工信息
	case 2:
		test.show_file();
		break;//显示职工信息
	case 3:
		test.del_worker();
		break;//删除离职员工
	case 4:
		test.mod_worker();
		break;//修改职工信息
	case 5:
		test.find_worker();
		break;//查找职工信息
	case 6:
		break;//按照编号排序
	case 7:
		break;//清空所有文档
	default:
		system("cls");//清屏操作 *
		break;
	}
	workmanager test;
	return 0;

}