#include "orderFile.h"
#include<fstream>

orderFile::orderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	string date;		// ԤԼ����
	string interval;	// ʱ���
	string stuId;		// ѧ��ID
	string stuName;		// ѧ������
	string roomId;		// ����ID
	string status;		// ԤԼ״̬

	this->m_Size = 0;

	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		// ���Դ���
		//cout <<  date << endl;
		//cout <<  interval << endl;
		//cout <<  stuId << endl;
		//cout <<  stuName << endl;
		//cout <<  roomId << endl;
		//cout <<  status		<< endl;


		string key, value;
		map<string, string> m;
		int pos = date.find(":"); // 4
		if (pos != -1)
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = interval.find(":"); // 4
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = stuId.find(":"); // 4
		if (pos != -1)
		{
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = stuName.find(":"); // 4
		if (pos != -1)
		{
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = roomId.find(":"); // 4
		if (pos != -1)
		{
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		
		pos = status.find(":"); // 4
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		this->m_orderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;
	}
	ifs.close();
}
void orderFile::updataOrder()
{
	if (this->m_Size == 0)
	{
		return;
	}
	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);

	for (int i = 0; i < this->m_Size; i++)
	{
		ofs << "date:"		<< this->m_orderData[i]["date"] << " ";
		ofs << "interval:"	<< this->m_orderData[i]["interval"] << " ";
		ofs << "stuId:"		<< this->m_orderData[i]["stuId"] << " ";
		ofs << "stuName:"	<< this->m_orderData[i]["stuName"] << " ";
		ofs << "roomId:"	<< this->m_orderData[i]["roomId"] << " ";
		ofs << "status:"	<< this->m_orderData[i]["status"] << endl;
	}
	ofs.close();
}