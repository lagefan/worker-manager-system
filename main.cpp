#include<iostream>
using namespace std;
#include"workers.h"
#include<string>
#include"workermanage.h"
int main()
{
	workmanager test;
	test.showmenu();
	cout << "��������Ҫ���еĲ���" << endl;
	int operatornum;
	cin >> operatornum;
	switch (operatornum)
	{
	case 0:
		test.save();
		test.exitsystem();
		break;//�˳�����ϵͳ *
	case 1:
		test.worker_add();
		break;//����ְ����Ϣ
	case 2:
		test.show_file();
		break;//��ʾְ����Ϣ
	case 3:
		test.del_worker();
		break;//ɾ����ְԱ��
	case 4:
		test.mod_worker();
		break;//�޸�ְ����Ϣ
	case 5:
		test.find_worker();
		break;//����ְ����Ϣ
	case 6:
		break;//���ձ������
	case 7:
		break;//��������ĵ�
	default:
		system("cls");//�������� *
		break;
	}
	workmanager test;
	return 0;

}