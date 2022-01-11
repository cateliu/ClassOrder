#pragma once
#include<string>
#include "computerRoom.h"
using namespace std;
class Identity // 老师、学生和职工的base
{
public:
	//操作菜单
	virtual void operMenu() = 0; // 纯虚函数
	string			m_Name;
	string			m_Pwd;
};