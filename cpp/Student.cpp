#include "Student.h"
#include "globalFile.h"
#include<iostream>
#include <fstream>
using namespace std;
Student::Student()
{
	//this->m_Name = NULL;
	//this->m_Id = 0;
	//this->m_Pwd = NULL;
}

// �вι���
Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

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
	// cout << "��ǰ��������Ϊ��" << this->vRom.size() << endl;
	ifs.close();


}

// �˵�����
void Student::operMenu()
{
	cout << "��ӭѧ������" << this->m_Name << "��¼" << endl;
	cout << "		----------------------------------------		" << endl;
	cout << "		|                                       |		" << endl;
	cout << "		|          1. �� �� Ԥ Լ                |		" << endl;
	cout << "		|                                       |		" << endl;
	cout << "		|          2. �鿴�ҵ�ԤԼ                |		" << endl;
	cout << "		|                                       |		" << endl;
	cout << "		|          3. �鿴����ԤԼ                 |		" << endl;
	cout << "		|                                       |		" << endl;
	cout << "		|          4. ȡ �� Ԥ Լ                 |		" << endl;
	cout << "		|                                       |		" << endl;
	cout << "		|          0. ע �� �� ¼                 |		" << endl;
	cout << "		|                                       |		" << endl;
	cout << "		----------------------------------------		" << endl;

	cout << "��ѡ�����Ĳ�����  ";
}

// ����ԤԼ
void Student::applyOrder()
{
	cout << "��������ʱ��Ϊ��һ�����壡" << endl;
	cout << "����������ԤԼʱ�䣺" << endl;
	cout << "1. ��һ" << endl;
	cout << "2. �ܶ�" << endl;
	cout << "3. ����" << endl;
	cout << "4. ����" << endl;
	cout << "5. ����" << endl;
	int date = 0;		// ����
	int interval = 0;	// �����������
	int room = 0;		// ѡ�������

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		else
		{
			cout << "�����������������룡" << endl;
		}
	}

	cout << "����������ʱ��Σ�1. ���磻2. ����" << endl;
	while (true)
	{
		cin >> interval;
		if (interval == 1 | interval == 2)
		{
			break;
		}
		else
		{
			cout << "�����������������룡" << endl;
		}
	}

	cout << "��ѡ�������" << endl;
	cout << "1�Ż������������Ϊ��" << this->vRom[0].m_MaxNum << endl;
	cout << "2�Ż������������Ϊ��" << this->vRom[1].m_MaxNum << endl;

	while (true)
	{
		cin >> room;
		if (room == 1 | room == 2)
		{
			break;
		}
		else
		{
			cout << "��Ϣ������������������" << endl;
		}
	}

	cout << "ԤԼ�ɹ�������У�" << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);

	ofs << "date:"		<< date			<< " ";
	ofs << "interval:"	<< interval		<< " ";
	ofs << "stuId:"		<< this->m_Id	<< " ";
	ofs << "stuName:"	<< this->m_Name << " ";
	ofs << "roomId:"	<< room			<< " ";
	ofs << "status:"	<< 1			<< endl;
	
	ofs.close();
	system("pause");
	system("cls");
}

// �鿴�ҵ�ԤԼ
void Student::showMyOrder()
{
	orderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str()))
		{
			cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"];
			cout << " ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << " ������" << of.m_orderData[i]["roomId"];
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
	}
	system("pause");
}

// �鿴����ԤԼ
void Student::showAllOder()
{
	orderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << "��" << i << "����";
		cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"];
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

// ȡ��ԤԼ
void Student::cancelOrder()
{
	orderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
	}

	cout << "ֻ��ȡ��������˺���ԤԼ��ԤԼ��" << endl;

	vector<int> v;
	int index = 0;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str()))
		{
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
			{
				v.push_back(index);
				index++;
				cout << "��" << index << "����¼" << endl;
				cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"];
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
		}
	}
	while (true)
	{
		cout << "��ѡ��ԤԼ��¼,0������:";
		int select;
		cin >> select;

		if (select > 0 && select <= v.size())
		{
			of.m_orderData[v[select - 1]]["status"] = "0";
			of.updataOrder();
			cout << "ȡ���ɹ���" << endl;
		}
		else if (select == 0)
		{
			break;
		}
		else
		{
			cout << "������������������" << endl;
		}
	}
	
	system("pause");
	system("cls");


}
