#pragma once
#include<iostream>
#include<map>
#include"globalFile.h"
using namespace std;


class orderFile
{
public:
	orderFile();		//	���캯��

	void updataOrder();	// ����ԤԼ��¼

	// key -- ��¼��������value -- �����¼�ļ�ֵ����Ϣ
	map<int, map<string, string>> m_orderData;

	// ԤԼ������Ϣ
	int m_Size;
};