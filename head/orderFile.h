#pragma once
#include<iostream>
#include<map>
#include"globalFile.h"
using namespace std;


class orderFile
{
public:
	orderFile();		//	构造函数

	void updataOrder();	// 更新预约记录

	// key -- 记录的条数；value -- 具体记录的键值对信息
	map<int, map<string, string>> m_orderData;

	// 预约条数信息
	int m_Size;
};