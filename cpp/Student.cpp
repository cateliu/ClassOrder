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

// 有参构造
Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

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
	// cout << "当前机房数量为：" << this->vRom.size() << endl;
	ifs.close();


}

// 菜单界面
void Student::operMenu()
{
	cout << "欢迎学生代表：" << this->m_Name << "登录" << endl;
	cout << "		----------------------------------------		" << endl;
	cout << "		|                                       |		" << endl;
	cout << "		|          1. 申 请 预 约                |		" << endl;
	cout << "		|                                       |		" << endl;
	cout << "		|          2. 查看我的预约                |		" << endl;
	cout << "		|                                       |		" << endl;
	cout << "		|          3. 查看所有预约                 |		" << endl;
	cout << "		|                                       |		" << endl;
	cout << "		|          4. 取 消 预 约                 |		" << endl;
	cout << "		|                                       |		" << endl;
	cout << "		|          0. 注 销 登 录                 |		" << endl;
	cout << "		|                                       |		" << endl;
	cout << "		----------------------------------------		" << endl;

	cout << "请选择您的操作：  ";
}

// 申请预约
void Student::applyOrder()
{
	cout << "机房开放时间为周一到周五！" << endl;
	cout << "请输入申请预约时间：" << endl;
	cout << "1. 周一" << endl;
	cout << "2. 周二" << endl;
	cout << "3. 周三" << endl;
	cout << "4. 周四" << endl;
	cout << "5. 周五" << endl;
	int date = 0;		// 日期
	int interval = 0;	// 上午或者下午
	int room = 0;		// 选择机房号

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		else
		{
			cout << "输入有误，请重新输入！" << endl;
		}
	}

	cout << "请输入申请时间段：1. 上午；2. 下午" << endl;
	while (true)
	{
		cin >> interval;
		if (interval == 1 | interval == 2)
		{
			break;
		}
		else
		{
			cout << "输入有误，请重新输入！" << endl;
		}
	}

	cout << "请选择机房：" << endl;
	cout << "1号机房的最大容量为：" << this->vRom[0].m_MaxNum << endl;
	cout << "2号机房的最大容量为：" << this->vRom[1].m_MaxNum << endl;

	while (true)
	{
		cin >> room;
		if (room == 1 | room == 2)
		{
			break;
		}
		else
		{
			cout << "信息输入有误，请重新输入" << endl;
		}
	}

	cout << "预约成功，审核中！" << endl;

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

// 查看我的预约
void Student::showMyOrder()
{
	orderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str()))
		{
			cout << "预约日期：周" << of.m_orderData[i]["date"];
			cout << " 时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << " 机房：" << of.m_orderData[i]["roomId"];
			string status = " 状态："; // 0 取消预约，1 审核中，2 已预约， -1 预约失败
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "审核中";
			}
			else if (of.m_orderData[i]["status"] == "0")
			{
				status += "取消预约";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "已预约";
			}
			else
			{
				status += "预约失败";
			}
			cout << status << endl;
		}
	}
	system("pause");
}

// 查看所有预约
void Student::showAllOder()
{
	orderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << "第" << i << "条：";
		cout << "预约日期：周" << of.m_orderData[i]["date"];
		cout << " 时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
		cout << " 机房：" << of.m_orderData[i]["roomId"];
		cout << " 学号：" << of.m_orderData[i]["stuId"];
		cout << " 姓名：" << of.m_orderData[i]["stuName"];
		string status = " 状态："; // 0 取消预约，1 审核中，2 已预约， -1 预约失败
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_orderData[i]["status"] == "0")
		{
			status += "取消预约";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "已预约";
		}
		else
		{
			status += "预约失败";
		}
		cout << status << endl;
	}

	system("pause");
	system("cls");
}

// 取消预约
void Student::cancelOrder()
{
	orderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
	}

	cout << "只能取消正在审核和已预约的预约。" << endl;

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
				cout << "第" << index << "条记录" << endl;
				cout << "预约日期：周" << of.m_orderData[i]["date"];
				cout << " 时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
				cout << " 机房：" << of.m_orderData[i]["roomId"];
				cout << " 学号：" << of.m_orderData[i]["stuId"];
				cout << " 姓名：" << of.m_orderData[i]["stuName"];
				string status = " 状态："; // 0 取消预约，1 审核中，2 已预约， -1 预约失败
				if (of.m_orderData[i]["status"] == "1")
				{
					status += "审核中";
				}
				else if (of.m_orderData[i]["status"] == "0")
				{
					status += "取消预约";
				}
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "已预约";
				}
				else
				{
					status += "预约失败";
				}
				cout << status << endl;
			}
		}
	}
	while (true)
	{
		cout << "请选择预约记录,0代表返回:";
		int select;
		cin >> select;

		if (select > 0 && select <= v.size())
		{
			of.m_orderData[v[select - 1]]["status"] = "0";
			of.updataOrder();
			cout << "取消成功！" << endl;
		}
		else if (select == 0)
		{
			break;
		}
		else
		{
			cout << "输入有误，请重新输入" << endl;
		}
	}
	
	system("pause");
	system("cls");


}
