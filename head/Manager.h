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
	// Ĭ�Ϲ���
	Manager();

	// �вι���
	Manager(string name, string pwd);
	
	// ��ʼ������
	void initVector();

	// ����
	bool checkRepeat(int i, int type);

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