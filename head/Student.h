#pragma once
#include "Identity.h"
#include "orderFile.h"
#include <vector>
class Student : public Identity
{
public:
	// 默认构造
	Student();

	// 有参构造
	Student(int id, string name, string pwd);

	// 菜单界面
	virtual void operMenu();

	// 申请预约
	void applyOrder();

	// 查看我的预约
	void showMyOrder();

	// 查看所有预约
	void showAllOder();

	// 取消预约
	void cancelOrder();

	// 学生学号
	int		m_Id;

	// 机房信息
	vector<computerRoom> vRom;
};