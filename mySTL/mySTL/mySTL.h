#ifndef _MYSTL_H_
#define _MYSTL_H_
#include<iostream>
#include<memory>//For memset
#include<string>
using namespace std;
const int MAX_LENTH = 1000;
template<class T>
class CIntList
{
public:
	CIntList();
	~CIntList();
	int Add(T TVal);//��ӣ�����ֵ �ɹ�1��ʧ��0
	int Delete();//ɾ�����һ��Ԫ��
	void Show();//��ӡȫ��Ԫ��
	T GetValueAt(int iPlace);//��ȡָ��λ�õ�ֵ������ֵ �ɹ�1��Խ�����һ��ֵ
private:
	T m_iList[MAX_LENTH];
	int m_length;
};

template<class T>
CIntList<T>::CIntList()
{
	m_length = 0;
}

template<class T>
CIntList<T>::~CIntList(){}

//��ӣ�����ֵ �ɹ�1��ʧ��0
template<class T>
int CIntList<T>::Add(T Val)
{
	//���洢�ռ�
	if (m_length == MAX_LENTH)
	{
		return 0;
	}
	else
	{
		m_iList[m_length] = Val;
		m_length++;
		return 1;
	}
}

//ɾ�����һ��Ԫ��
template<class T>
int CIntList<T>::Delete()
{
	//����Ƿ���Ԫ��
	if (m_length == 0)
	{
		return 0;
	}
	else
	{
		m_length--;
	}
}

//��ӡȫ��Ԫ��
template<class T>
void CIntList<T>::Show()
{
	for (int i = 0; i < m_length; i++)
	{
		cout << m_iList[i] << endl;
	}
}

//��ȡָ��λ�õ�ֵ������ֵ �ɹ�����ֵ��Խ�����һ��ֵ
template<class T>
T CIntList<T>::GetValueAt(int iPlace)
{
	//����Ƿ����Խ��
	if (iPlace>m_length)
	{
		cout << "GetValueAt Transboundary!" << endl;
		return m_iList[m_length - 1];
	}
	else
	{
		return m_iList[iPlace-1];
	}
}


#endif // !_MYSTL_H_
