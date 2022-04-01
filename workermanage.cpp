#include<iostream>
using namespace std;
#include"workermanage.h"
#include<fstream>
#define FILENAME "demo.txt"
workmanager::workmanager()//���캯��
{
	//�ļ������ڵ����
	ifstream ist;
	ist.open(FILENAME, ios::in);
	if (!ist.is_open()) 
	{
		cout << "�ļ�������" << endl;
		this->file_isempty = true;
		this->workerarr = NULL;
		this->workerNUM = 0;
		ist.close();
		return;
	}
	//�ļ����ڵ�û�м�¼�����
	char c;
	ist >> c;
	if (ist.eof())//���cû�ж�ȡ�����ݣ���.eof()����Ϊ1
	{
		cout << "�ļ�Ϊ��" << endl;
		this->file_isempty = true;
		this->workerarr = NULL;
		this->workerNUM = 0;
		ist.close();
		return;
	}
	//�ļ����ڣ����Һ�������
	this->workerNUM = this->get_filenum();
	this->file_isempty = false;
	//��������
	this->workerarr = new worker * [this->workerNUM];
	//���ó�ʼ������
	this->init();
	//���Դ���
	/*for (int i = 0; i < this->workerNUM; i++)
	{
		this->workerarr[i]->showinfo();
	}*/
}
workmanager::~workmanager()//��������
{
	if (this->workerarr != NULL)
	{
		delete[]this->workerarr;
		this->workerarr = NULL;
	}
}
void workmanager::showmenu()//��ʾ�˵�
{
		cout << "��ӭʹ��ְ������ϵͳ" << endl;
		cout << "0 �˳��������" << endl;
		cout << "1 ����ְ����Ϣ" << endl;
		cout << "2 ��ʾְ����Ϣ" << endl;
		cout << "3 ɾ����ְԱ��" << endl;
		cout << "4 �޸�ְ����Ϣ" << endl;
		cout << "5 ����ְ����Ϣ" << endl;
		cout << "6 ���ձ������" << endl;
		cout << "7 ��������ĵ�" << endl;
		cout << endl;
}
void workmanager::exitsystem()//�˳�����
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}
void workmanager::worker_add()
{
	cout << "��������Ҫ��ӵ�ְ����" << endl;
	int t_num;
	cin >> t_num;
	int newsize = this->workerNUM + t_num;
	if (t_num <= 0) { cout << "���Ǹ�ɵ��,�����Զ���ֹ" << endl; return; }
	worker**newspace = new worker * [newsize];
	if (this->workerNUM > 0)//ѭ�������ݿ��е�����Ǩ�Ƶ��µĿռ���
	{
		for (int i = 0; i < (this->workerNUM); i++)
		{
			newspace[i] = this->workerarr[i];
		}
	}
	for (int j=0; j < t_num; j++)//��������
	{
		int i_id;
		string i_name;
		int i_depnum;
		cout << "�������" << j + 1 << "λԱ�����" << endl;
		cin >> i_id;
		cout << "�������" << j + 1 << "λԱ������" << endl;
		cin >> i_name;
		cout << "�������" << j + 1 << "λԱ����λ���" << endl;
		cout << "1 ����" << endl;
		cout << "2 ����" << endl;
		cout << "3 �ϰ�" << endl;
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
				cout << "���Ǹ�ɵ��" << endl;
				cout << "�Զ���ֹ" << endl;
				return;
		}
		newspace[this->workerNUM + j] = index;
	}
	cout << "��ӳɹ���" << endl;
	this->workerNUM = newsize;//�������ݿ�Ĵ�С
	delete[] this->workerarr;//�ͷ�ԭ�пռ�
	this->workerarr = newspace;//����ָ��
}
void workmanager::save()//��Ա������д�뵽�ļ���
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->workerNUM; i++)
	{
		ofs << this->workerarr[i]->w_id << "\t" << this->workerarr[i]->w_name << "\t" << this->workerarr[i]->w_depid << endl;
	}
	ofs.close();
}
int workmanager::get_filenum()//��ȡ�ļ���Ա���ĸ���
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
void workmanager::init()//���ļ��л�ȡԱ������
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
void workmanager::show_file()//��ʾԱ��
{
	if (this->file_isempty == true)
	{
		cout << "���ݿ���û�����ݣ������������" << endl;
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
	if (this->file_isempty == true) { cout << "�ļ�Ϊ�գ�û�пɲ��������ݣ�" << endl; return; }
	int d_id;
	cout << "����������ɾ����Ա����ID" << endl;
	cin >> d_id;
	if (this->worker_isexist(d_id) != -1)
	{
		for (int i = this->worker_isexist(d_id)-1/*��һ��û���뵽��������*/; i < this->workerNUM; i++)
		{
			this->workerarr[i] = this->workerarr[i + 1];//����ǰ��ʵ��ɾ������
		}
		this->save();//�������ݿ�
		cout << "delete successfully" << endl;
	}
	else { cout << "��Ա��������" << endl; }
	system("pause");
	system("cls");
}
void workmanager::mod_worker()
{
	if (this->file_isempty == true) { cout << "�ļ�Ϊ�գ�û�пɲ��������ݣ�" << endl; return; }
	int d_id;
	cout << "�����������޸ĵ�Ա����ID" << endl;
	cin >> d_id;
	if (this->worker_isexist(d_id) != -1)
	{
		int d_id;
		int id;
		string name;
		int dep_id;
		int temp;
		cout << "��������Ҫ�޸ĵ�Ա����ְ�����" << endl;
		cin >> d_id;
		cout << "��������Ҫ�޸ĵ�Ա������" << endl;
		cout << "1 Ա�����" << endl;
		cout << "2 Ա������" << endl;
		cout << "3 Ա�����ű��" << endl;
		cin >> temp;
		if (temp == 1) 
		{
			cout << "�������޸ĺ��Ա�����" << endl;
			cin >> id;
			this->workerarr[this->worker_isexist(d_id)]->w_id = id;
			this->save();
			cout << "�޸ĳɹ���" << endl;
		}
		if (temp == 2)
		{
			cout << "�������޸ĺ��Ա������" << endl;
			cin >> name;
			this->workerarr[this->worker_isexist(d_id)]->w_name = name;
			this->save();
			cout << "�޸ĳɹ���" << endl;
		}
		if (temp == 3)
		{
			cout << "����������Ҫ�޸ĵ�Ա�����ű��" << endl;
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
				cout << "���ű�Ų����ڣ�" << endl;
				break;
			}
			this->workerarr[this->worker_isexist(d_id)] = index;
			this->save();
			cout << "�޸ĳɹ���" << endl;
		}
	}
	else { cout << "��Ա��������" << endl; }
	system("pause");
	system("cls");
}
void workmanager::find_worker()//����Ա��ID���������ַ�ʽ����
{
	if (this->file_isempty == true) { cout << "�ļ�Ϊ��" << endl; return; }
	cout << "��������Ҫ���ҵķ�ʽ" << endl;
	cout << "1 ����Ա��ID����" << endl;
	cout << "2 ����Ա����������" << endl;
	int num;
	cin >> num;
	bool flag = false;//�ؼ��㣺��һ��û���뵽
	switch (num)
	{
	case 1:
		cout << "��������Ҫ���ҵ�ID" << endl;
		int d_id;
		cin >> d_id;
		int index = this->worker_isexist(d_id);
		if (index != -1) { this->workerarr[index]->showinfo(); flag = true; }
		break;
	case 2:
	{cout << "��������Ҫ���ҵ�����" << endl;
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
		cout << "��������ȷ������" << endl;
		break;
	}
	if (flag == true)
	{
		cout << "����ɹ���" << endl;
	}
	else { cout << "���޴���" << endl; }
}
void workmanager::clear_file()
{
	cout << "ȷ������ļ���" << endl;
	cout << "1 ȷ��" << endl;
	cout << "2 ����" << endl;
	int temp;
	cin >> temp;
	if (temp == 1)
	{
		ofstream ofs;
		ofs.open(FILENAME, ios::trunc);//��ģʽios::trunc,��������ļ�ɾ�������´���
		ofs.close();
		if (this->workerarr != NULL)
		{
			for (int i = 0; i < this->workerNUM; i++)
			{
				delete this->workerarr[i];
			}
			this->workerNUM = 0;//�������в���
			delete[]this->workerarr;
			this->workerarr = NULL;
			this->file_isempty = true;
			cout << "��ʽ���ɹ���" << endl;
		}
	}
	system("pause");
	system("cls");
}