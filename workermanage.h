#pragma once
#include<iostream>
using namespace std;
#include"workers.h"
class workmanager
{
	int workerNUM;
	worker** workerarr;
	bool file_isempty;//����ļ�Ϊ�գ��򲻱�Ҫ�޸���ʾ�ļ�
	
public:
	workmanager();
	~workmanager();
	void showmenu();//��ʾ�˵�
	void exitsystem();//�˳�ϵͳ
	void worker_add();//���Ա��
	void save();//д�ļ�
	int get_filenum();//���ļ��л�ȡԱ�����������ں���ʹ��
	void init();//��ʼ������
	void show_file();//��ʾԱ������
	int worker_isexist(int id);//���������Ա������ж�Ա���Ƿ���ڣ�������ڷ���λ�ã������ڷ���-1;
	void del_worker();//�����ṩ��Ա��ID��ɾ��Ա��
	void mod_worker();//����Ա��ID���޸�Ա����Ϣ
	void find_worker();//����Ա��ID��Ա����������ѯ��Ϣ
	void clear_file();//����ļ�
};
