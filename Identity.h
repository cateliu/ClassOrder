#pragma once
#include<string>
using namespace std;
class Identity // ��ʦ��ѧ����ְ����base
{
public:
	//�����˵�
	virtual void operMenu() = 0; // ���麯��
	string			m_Name;
	string			m_Pwd;
};