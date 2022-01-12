#include<iostream>
#include<fstream>
#include "Student.h"
#include "Teacher.h"
#include "Manager.h"
#include "globalFile.h"
using namespace std;
 
void teacherMenu(Identity* &teacher)
{
	while (true)
	{
		system("cls");

		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;

		int select;
		cin >> select;

		if (select == 1) // �鿴����ԤԼ
		{
			tea->showAllorder();
		}
		else if (select == 2) // ���ԤԼ
		{
			tea->validOrder();
		}
		else // ע����¼
		{
			delete tea;
			cout << "ע����¼��" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void studentMenu(Identity* &student)
{
	while (true)
	{
		// ѧ���˵�
		system("cls");
		student->operMenu();

		Student* st = (Student*)student;

		int select;
		cin >> select;


		if (select == 1)	// ����ԤԼ
		{
			st->applyOrder();
		}
		else if (select == 2) // �鿴����ԤԼ
		{
			st->showMyOrder();
		}
		else if (select == 3) // �鿴����ԤԼ
		{
			st->showAllOder();
		}
		else if (select == 4) // ȡ��ԤԼ
		{
			st->cancelOrder();
		}
		else
		{
			delete st;
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void manageMenu(Identity*& manager)
{
	while (true)
	{
		// ����Ա�˵�
		manager->operMenu();
		Manager* man = (Manager*)manager;
		int select = 0;

		cin >> select;

		if (select == 1)
		{
			cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2)
		{
			cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3)
		{
			cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4)
		{
			cout << "���ԤԼ��Ϣ" << endl;
			man->cleanFile();
		}
		else
		{
			//delete manager;
			cout << "ע���ɹ�" << endl;
			system("pause");
			return;
		}
	}
}

// fileName		-- �������ļ���
// type			-- ��ݣ�1����ѧ����2������ʦ��3�������Ա��
void LogIn(string fileName, int type) // ȫ�ֺ�������¼
{
	Identity* person = NULL;
	ifstream ifs;

	ifs.open(fileName, ios::in);
	// �ļ�������
	if (!ifs.is_open())
	{
		cout << "���ļ�������" << endl;
		ifs.close();
		return;
	}

	int Id = 0;
	string name;
	string pwd;

	switch (type)
	{
	case 1:
		cout << "���������ѧ�ţ�";
		cin >> Id;
		break;
	case 2:
		cout << "��������Ľ�ʦ�ţ�";
		cin >> Id;
	case 3:
		break;
	default:
		return;
		break;
	}

	cout << "���������������";
	cin >> name;
	cout << "������������룺";
	cin >> pwd;

	switch (type)
	{
	case 1:				// ѧ����¼��֤
	{
		int fId;		// ���ļ���ȡ��ID��
		string fName;	// ���ļ���ȡ������
		string fPwd;	// ���ļ���ȡ������
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == Id && fName == name && fPwd == pwd)
			{
				cout << "ѧ����¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Student(Id, name, pwd);
				// ����ѧ����ݵ��Ӳ˵�
				studentMenu(person);
				return;
			}
		}
		break;
	}
	case 2:				// ��ʦ��¼��֤
	{
		int fId;		// ���ļ���ȡ��ID��
		string fName;	// ���ļ���ȡ������
		string fPwd;	// ���ļ���ȡ������
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == Id && fName == name && fPwd == pwd)
			{
				cout << "��ʦ��¼�ɹ���" << endl;
				system("pause");
				person = new Teacher(Id, name, pwd);
				// ������ʦ��ݵ��Ӳ˵�
				teacherMenu(person);
				return;
			}
		}
		break;
	}
	case 3:				// ����Ա��¼��֤
	{
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd)
			{
				cout << "����Ա��¼�ɹ��� " << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				// �������Ա���Ӳ˵�
				manageMenu(person);
				delete person;
				return;
			}
		}
		break;
	}
	default:
		break;
	}
	ifs.close();
	cout << "��֤��¼ʧ�ܣ�" << endl;
	system("pause");
	return;


}
void ShowMenu()
{
	system("cls");

	cout << "**************************  ��ӭ��������ԤԼϵͳ  ****************************"
		<< endl;
	cout << "\t -------------------------------------------------------\n";
	cout << "\t|\t\t\t 1.ѧ������ \t\t\t|\n";
	cout << "\t|\t\t\t\t\t\t\t|\n";
	cout << "\t|\t\t\t 2.��    ʦ \t\t\t|\n";
	cout << "\t|\t\t\t\t\t\t\t|\n";
	cout << "\t|\t\t\t 3.�� �� Ա \t\t\t|\n";
	cout << "\t|\t\t\t\t\t\t\t|\n";
	cout << "\t|\t\t\t 0.��    �� \t\t\t|\n";
	cout << "\t|\t\t\t\t\t\t\t|\n";
	cout << "\t -------------------------------------------------------\n";

	cout << endl << "������������ݣ�";
	//cout << "\t|                                                   |\n";
	//cout << "\t|                     1.ѧ������                    |\n";
	//cout << "\t|                                                   |\n";
	//cout << "\t|                     2.��    ʦ                    |\n";
	//cout << "\t|                                                   |\n";
	//cout << "\t|                     3.�� �� Ա                    |\n";
	//cout << "\t|                                                   |\n";
	//cout << "\t|                     4.��    ��                    |\n";
	//cout << "\t|                                                   |\n";
	//cout << "\t|                                                   |\n";
	//cout << "\t ---------------------------------------------------\n";

	//cout << "��������ѡ��";

	

}

int main()
{
	Teacher t1;
	Manager m1;
	//string filename;
	//cin >> filename;
	//cout << "file name is : " << filename << endl;
	int choice = 0;
	while (true)
	{
		ShowMenu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			LogIn(STUDENT_FILE, 1);
			break;
		case 2:
			LogIn(TEACHER_FILE, 2);
			break;
		case 3:
			LogIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "��ӭ��һ��ʹ��" << endl;
			system("pause");
			return 0;
		default:
			cout << "ѡ����������ѡ��" << endl;
			system("pause");
			break;
		}
	}
	
	return 1;
}