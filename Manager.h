#pragma once
#include "Identity.h"

class Manager :public Identity
{
public:
	// Ĭ�Ϲ���
	Manager();

	// �вι���
	Manager(string name, string pwd);

	// ��ʾ�˵�
	virtual void operMenu();

	// ����˺�
	void addPerson();

	// �鿴�˺�
	void showPerson();

	// �鿴������Ϣ
	void showComputer();

	// ���ԤԼ��Ϣ
	void cleanFile();
};