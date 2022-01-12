#include "Teacher.h"
#include<iostream>
#include <vector>
#include"orderFile.h"
using namespace std;
// Ĭ�Ϲ���
Teacher::Teacher()
{

}

// �вι���
Teacher::Teacher(int empId, string name, string pwd)
{
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

//�˵�����
void Teacher::operMenu()
{
	cout << "��ӭ��ʦ��" << this->m_Name << "��¼" << endl;
	cout << "		----------------------------------------		" << endl;
	cout << "		|                                       |		" << endl;
	cout << "		|          1. �鿴����ԤԼ                |		" << endl;
	cout << "		|                                       |		" << endl;
	cout << "		|          2. �� �� Ԥ Լ                |		" << endl;
	cout << "		|                                       |		" << endl;
	cout << "		|          0. ע �� �� ¼                 |		" << endl;
	cout << "		|                                       |		" << endl;
	cout << "		----------------------------------------		" << endl;

	cout << "��ѡ�����Ĳ�����  ";
}

//�鿴����ԤԼ
void Teacher::showAllorder()
{
	orderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout <<  i + 1;
		cout << ", ԤԼ���ڣ���" << of.m_orderData[i]["date"];
		cout << " ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
		cout << " ������" << of.m_orderData[i]["roomId"];
		cout << " ѧ�ţ�" << of.m_orderData[i]["stuId"];
		cout << " ������" << of.m_orderData[i]["stuName"];
		string status = " ״̬��"; // 0 ȡ��ԤԼ��1 ����У�2 ��ԤԼ�� -1 ԤԼʧ��
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.m_orderData[i]["status"] == "0")
		{
			status += "ȡ��ԤԼ";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "��ԤԼ";
		}
		else
		{
			status += "ԤԼʧ��";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

//���ԤԼ
void Teacher::validOrder()
{
	orderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����˵�ԤԼ���£�" << endl;

	int index = 0;
	vector<int> v;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (of.m_orderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << index + 1;
			cout << ", ԤԼ���ڣ���" << of.m_orderData[i]["date"];
			cout << " ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << " ������" << of.m_orderData[i]["roomId"];
			cout << " ѧ�ţ�" << of.m_orderData[i]["stuId"];
			cout << " ������" << of.m_orderData[i]["stuName"];
			cout << " ״̬�������" << endl;
			index++;
			
		}
	}
	int select;
	int ret;
	while (true)
	{
		cout << "���������˵����룬����0�˻�ԭ���棡"<< endl;
		cin >> select;
		
		if (select > 0 && select <= v.size())
		{
			cout << "��������˽����" << endl;
			cout << "1. ͨ��" << endl;
			cout << "2. ��ͨ��" << endl;
			cin >> ret;
			if (ret == 1)
			{
				of.m_orderData[v[select - 1]]["status"] = "2";
			}
			else
			{
				of.m_orderData[v[select - 1]]["status"] = "-1";
			}
			of.updataOrder();
			cout << "�����ϣ�" << endl;
			break;
		}
		else if (select == 0)
		{
			break;
		}
		else
		{
			cout << "�����������������롣" << endl;
		}
	}
}