#pragma once
#include "Identity.h"

class Teacher: public Identity
{
public:
	// Ĭ�Ϲ���
	Teacher();

	// �вι���
	Teacher(int empId, string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//�鿴����ԤԼ
	void showAllorder();

	//���ԤԼ
	void validOrder();

	int m_EmpId;
};