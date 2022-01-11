#include "Manager.h"
#include <iostream>
#include <fstream>
#include "globalFile.h"
Manager::Manager()
{
	
}

// �вι���
Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;
	this->initVector();
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�����ļ���ʧ�ܣ�" << endl;
		return;
	}
	computerRoom C;
	while (ifs >> C.m_Rid && ifs >> C.m_MaxNum)
	{
		this->vRom.push_back(C);
	}
	cout << "��ǰ��������Ϊ��" << this->vRom.size() << endl;
	ifs.close();
}

void Manager::initVector()
{
	this->vStu.clear();
	this->vTea.clear();
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	// ��ȡѧ���ļ�
	Student S;
	while (ifs >> S.m_Id && ifs >> S.m_Name && ifs >> S.m_Pwd)
	{
		this->vStu.push_back(S);
	}

	cout << "��ǰѧ������Ϊ��" << vStu.size() << endl;

	ifs.close();
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	Teacher T;
	while (ifs >> T.m_EmpId && ifs >> T.m_Name && ifs >> T.m_Pwd)
	{
		this->vTea.push_back(T);
	}

	cout << "��ǰ��ʦ����Ϊ��" << vTea.size() << endl;



	ifs.close();
}

bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = this->vStu.begin(); it != this->vStu.end(); it++)
		{
			if (id == it->m_Id)
				return true;
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = this->vTea.begin(); it != this->vTea.end(); it++)
		{
			if (id == it->m_EmpId)
				return true;
		}
	}
	return false;
}


// ��ʾ�˵�
void Manager::operMenu()
{
	cout << "��ӭ����Ա��" << this->m_Name << "��¼" << endl;
	cout << "		----------------------------------------		" << endl;
	cout << "		|                                       |		" << endl;
	cout << "		|          1. �� �� �� ��                |		" << endl;
	cout << "		|                                       |		" << endl;
	cout << "		|          2. �� �� �� ��                |		" << endl;
	cout << "		|                                       |		" << endl;
	cout << "		|          3. �� �� �� ��                 |		" << endl;
	cout << "		|                                       |		" << endl;
	cout << "		|          4. �� �� Ԥ Լ                 |		" << endl;
	cout << "		|                                       |		" << endl;
	cout << "		|          0. ע �� �� ¼                 |		" << endl;
	cout << "		|                                       |		" << endl;
	cout << "		----------------------------------------		" << endl;

	cout << "��ѡ�����Ĳ�����  ";
}

// ����˺�
void Manager::addPerson()
{
	cout << "����������˺ŵ����ͣ�" << endl;
	cout << "1. ���ѧ��" << endl;
	cout << "2. �����ʦ" << endl;
	
	string fileName;
	string tip;
	string errorTip; //		�ظ�������ʾ
	ofstream ofs;
	int select;
	cin >> select;

	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		errorTip = "ѧ���ظ�������������:";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "������ְ����ţ�";
		errorTip = "ְ�����ظ�������������:";
	}
	ofs.open(fileName, ios::out | ios:: app);
	int id;
	string name;
	string pwd;
	cout << tip;
	while (true)
	{
		cin >> id;
		bool ret = this->checkRepeat(id, select);
		if (ret)
		{
			cout << errorTip;
		}
		else
		{
			break;
		}

	}

	cout << "������������";
	cin >> name;
	cout << "���������룺";
	cin >> pwd;


	ofs << id << " " << name << " " << pwd << endl;
	cout << "��ӳɹ�" << endl;
	system("pause");
	system("cls");
	ofs.close();

	if (select == 1)
	{
		this->vStu.push_back(Student(id, name, pwd));
	}
	else
	{
		Teacher T(id, name, pwd);
		this->vTea.push_back(T);
	}
}

// �鿴�˺�
void Manager::showPerson()
{
	cout << "��ѡ��鿴���ݣ�" << endl;
	cout << "1. ѧ��" << endl;
	cout << "2. ��ʦ" << endl;
	int select;
	cin >> select;
	if (select == 1)
	{
		for (vector<Student>::iterator it = this->vStu.begin(); it != this->vStu.end(); it++)
		{
			cout << "ѧ�ţ�"<<it->m_Id << " ������" << it->m_Name << endl;
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = this->vTea.begin(); it != this->vTea.end(); it++)
		{
			cout << "��ʦ��ţ�" << it->m_EmpId << " ������" << it->m_Name << endl;
		}
	}
	system("pause");
	system("cls");
}

// �鿴������Ϣ
void Manager::showComputer()
{
	for (vector<computerRoom>::iterator it = this->vRom.begin(); it != this->vRom.end(); it++)
	{
		cout << "������Ϊ��" << it->m_Rid << " ���������������Ϊ��" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

// ���ԤԼ��Ϣ
void Manager::cleanFile()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "��ճɹ���" << endl;
	system("pause");
	system("als");
}