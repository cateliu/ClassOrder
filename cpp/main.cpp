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

		if (select == 1) // 查看所有预约
		{
			tea->showAllorder();
		}
		else if (select == 2) // 审核预约
		{
			tea->validOrder();
		}
		else // 注销登录
		{
			delete tea;
			cout << "注销登录！" << endl;
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
		// 学生菜单
		system("cls");
		student->operMenu();

		Student* st = (Student*)student;

		int select;
		cin >> select;


		if (select == 1)	// 申请预约
		{
			st->applyOrder();
		}
		else if (select == 2) // 查看自身预约
		{
			st->showMyOrder();
		}
		else if (select == 3) // 查看所有预约
		{
			st->showAllOder();
		}
		else if (select == 4) // 取消预约
		{
			st->cancelOrder();
		}
		else
		{
			delete st;
			cout << "注销成功！" << endl;
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
		// 管理员菜单
		manager->operMenu();
		Manager* man = (Manager*)manager;
		int select = 0;

		cin >> select;

		if (select == 1)
		{
			cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2)
		{
			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3)
		{
			cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4)
		{
			cout << "清空预约信息" << endl;
			man->cleanFile();
		}
		else
		{
			//delete manager;
			cout << "注销成功" << endl;
			system("pause");
			return;
		}
	}
}

// fileName		-- 操作的文件名
// type			-- 身份（1代表学生，2代表老师，3代表管理员）
void LogIn(string fileName, int type) // 全局函数，登录
{
	Identity* person = NULL;
	ifstream ifs;

	ifs.open(fileName, ios::in);
	// 文件不存在
	if (!ifs.is_open())
	{
		cout << "此文件不存在" << endl;
		ifs.close();
		return;
	}

	int Id = 0;
	string name;
	string pwd;

	switch (type)
	{
	case 1:
		cout << "请输入你的学号：";
		cin >> Id;
		break;
	case 2:
		cout << "请输入你的教师号：";
		cin >> Id;
	case 3:
		break;
	default:
		return;
		break;
	}

	cout << "请输入你的姓名：";
	cin >> name;
	cout << "请输入你的密码：";
	cin >> pwd;

	switch (type)
	{
	case 1:				// 学生登录验证
	{
		int fId;		// 从文件获取的ID号
		string fName;	// 从文件获取的姓名
		string fPwd;	// 从文件获取的密码
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == Id && fName == name && fPwd == pwd)
			{
				cout << "学生登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(Id, name, pwd);
				// 进入学生身份的子菜单
				studentMenu(person);
				return;
			}
		}
		break;
	}
	case 2:				// 老师登录验证
	{
		int fId;		// 从文件获取的ID号
		string fName;	// 从文件获取的姓名
		string fPwd;	// 从文件获取的密码
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == Id && fName == name && fPwd == pwd)
			{
				cout << "老师登录成功！" << endl;
				system("pause");
				person = new Teacher(Id, name, pwd);
				// 进入老师身份的子菜单
				teacherMenu(person);
				return;
			}
		}
		break;
	}
	case 3:				// 管理员登录验证
	{
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd)
			{
				cout << "管理员登录成功！ " << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				// 进入管理员的子菜单
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
	cout << "验证登录失败！" << endl;
	system("pause");
	return;


}
void ShowMenu()
{
	system("cls");

	cout << "**************************  欢迎来到机房预约系统  ****************************"
		<< endl;
	cout << "\t -------------------------------------------------------\n";
	cout << "\t|\t\t\t 1.学生代表 \t\t\t|\n";
	cout << "\t|\t\t\t\t\t\t\t|\n";
	cout << "\t|\t\t\t 2.老    师 \t\t\t|\n";
	cout << "\t|\t\t\t\t\t\t\t|\n";
	cout << "\t|\t\t\t 3.管 理 员 \t\t\t|\n";
	cout << "\t|\t\t\t\t\t\t\t|\n";
	cout << "\t|\t\t\t 0.退    出 \t\t\t|\n";
	cout << "\t|\t\t\t\t\t\t\t|\n";
	cout << "\t -------------------------------------------------------\n";

	cout << endl << "请输入您的身份：";
	//cout << "\t|                                                   |\n";
	//cout << "\t|                     1.学生代表                    |\n";
	//cout << "\t|                                                   |\n";
	//cout << "\t|                     2.老    师                    |\n";
	//cout << "\t|                                                   |\n";
	//cout << "\t|                     3.管 理 员                    |\n";
	//cout << "\t|                                                   |\n";
	//cout << "\t|                     4.退    出                    |\n";
	//cout << "\t|                                                   |\n";
	//cout << "\t|                                                   |\n";
	//cout << "\t ---------------------------------------------------\n";

	//cout << "输入您的选择：";

	

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
			cout << "欢迎下一次使用" << endl;
			system("pause");
			return 0;
		default:
			cout << "选择有误，重新选择！" << endl;
			system("pause");
			break;
		}
	}
	
	return 1;
}