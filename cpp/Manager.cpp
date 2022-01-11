#include "Manager.h"
#include <iostream>
#include <fstream>
#include "globalFile.h"
Manager::Manager()
{
	
}

// 有参构造
Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;
	this->initVector();
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "机房文件打开失败！" << endl;
		return;
	}
	computerRoom C;
	while (ifs >> C.m_Rid && ifs >> C.m_MaxNum)
	{
		this->vRom.push_back(C);
	}
	cout << "当前机房数量为：" << this->vRom.size() << endl;
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
		cout << "文件打开失败" << endl;
		return;
	}
	// 读取学生文件
	Student S;
	while (ifs >> S.m_Id && ifs >> S.m_Name && ifs >> S.m_Pwd)
	{
		this->vStu.push_back(S);
	}

	cout << "当前学生数量为：" << vStu.size() << endl;

	ifs.close();
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	Teacher T;
	while (ifs >> T.m_EmpId && ifs >> T.m_Name && ifs >> T.m_Pwd)
	{
		this->vTea.push_back(T);
	}

	cout << "当前老师数量为：" << vTea.size() << endl;



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


// 显示菜单
void Manager::operMenu()
{
	cout << "欢迎管理员：" << this->m_Name << "登录" << endl;
	cout << "		----------------------------------------		" << endl;
	cout << "		|                                       |		" << endl;
	cout << "		|          1. 添 加 账 号                |		" << endl;
	cout << "		|                                       |		" << endl;
	cout << "		|          2. 查 看 账 号                |		" << endl;
	cout << "		|                                       |		" << endl;
	cout << "		|          3. 查 看 机 房                 |		" << endl;
	cout << "		|                                       |		" << endl;
	cout << "		|          4. 清 空 预 约                 |		" << endl;
	cout << "		|                                       |		" << endl;
	cout << "		|          0. 注 销 登 录                 |		" << endl;
	cout << "		|                                       |		" << endl;
	cout << "		----------------------------------------		" << endl;

	cout << "请选择您的操作：  ";
}

// 添加账号
void Manager::addPerson()
{
	cout << "请输入添加账号的类型：" << endl;
	cout << "1. 添加学生" << endl;
	cout << "2. 添加老师" << endl;
	
	string fileName;
	string tip;
	string errorTip; //		重复错误提示
	ofstream ofs;
	int select;
	cin >> select;

	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "请输入学号：";
		errorTip = "学号重复，请重新输入:";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "请输入职工编号：";
		errorTip = "职工号重复，请重新输入:";
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

	cout << "请输入姓名：";
	cin >> name;
	cout << "请输入密码：";
	cin >> pwd;


	ofs << id << " " << name << " " << pwd << endl;
	cout << "添加成功" << endl;
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

// 查看账号
void Manager::showPerson()
{
	cout << "请选择查看内容：" << endl;
	cout << "1. 学生" << endl;
	cout << "2. 老师" << endl;
	int select;
	cin >> select;
	if (select == 1)
	{
		for (vector<Student>::iterator it = this->vStu.begin(); it != this->vStu.end(); it++)
		{
			cout << "学号："<<it->m_Id << " 姓名：" << it->m_Name << endl;
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = this->vTea.begin(); it != this->vTea.end(); it++)
		{
			cout << "教师编号：" << it->m_EmpId << " 姓名：" << it->m_Name << endl;
		}
	}
	system("pause");
	system("cls");
}

// 查看机房信息
void Manager::showComputer()
{
	for (vector<computerRoom>::iterator it = this->vRom.begin(); it != this->vRom.end(); it++)
	{
		cout << "机房号为：" << it->m_Rid << " 机房最大容纳数量为：" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

// 清空预约信息
void Manager::cleanFile()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "清空成功！" << endl;
	system("pause");
	system("als");
}