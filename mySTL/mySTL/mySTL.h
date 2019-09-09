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
	int Add(T TVal);//添加；返回值 成功1，失败0
	int Delete();//删除最后一个元素
	void Show();//打印全部元素
	T GetValueAt(int iPlace);//获取指定位置的值；返回值 成功1，越界最后一个值
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

//添加；返回值 成功1，失败0
template<class T>
int CIntList<T>::Add(T Val)
{
	//检查存储空间
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

//删除最后一个元素
template<class T>
int CIntList<T>::Delete()
{
	//检查是否有元素
	if (m_length == 0)
	{
		return 0;
	}
	else
	{
		m_length--;
	}
}

//打印全部元素
template<class T>
void CIntList<T>::Show()
{
	for (int i = 0; i < m_length; i++)
	{
		cout << m_iList[i] << endl;
	}
}

//获取指定位置的值；返回值 成功返回值，越界最后一个值
template<class T>
T CIntList<T>::GetValueAt(int iPlace)
{
	//检查是否访问越界
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
