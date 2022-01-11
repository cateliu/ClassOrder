#include "Student.h"

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
}

// 菜单界面
void Student::operMenu()
{

}

// 申请预约
void Student::applyOrder()
{

}

// 查看我的预约
void Student::showMyOrder()
{

}

// 查看所有预约
void Student::showAllOder()
{

}

// 取消预约
void Student::cancelOrder()
{

}
