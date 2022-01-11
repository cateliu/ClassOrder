#pragma once
#include "Identity.h"
#include <vector>
#include "Student.h"
#include "Teacher.h"

class Manager :public Identity
{
	vector<Student> vStu;
	vector<Teacher> vTea;
	vector<computerRoom> vRom;
public:
	// 默认构造
	Manager();

	// 有参构造
	Manager(string name, string pwd);
	
	// 初始化容器
	void initVector();

	// 查重
	bool checkRepeat(int i, int type);

	// 显示菜单
	virtual void operMenu();

	// 添加账号
	void addPerson();

	// 查看账号
	void showPerson();

	// 查看机房信息
	void showComputer();

	// 清空预约信息
	void cleanFile();
};