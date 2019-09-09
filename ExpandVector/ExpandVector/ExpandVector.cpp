#include"ExpandVector.h"
#include<iostream>
#include<algorithm>
#include <iterator>
#include<vector>
using namespace std;

//初始化
CExpandVector::CExpandVector()
{
	//Q1如何做到不定参数？
	cout << "输入初始化参数(空格分隔，ctr+z结束):" << endl;
	copy(istream_iterator <int> {cin}, istream_iterator <int> {}, back_inserter(m_vector));
}
//析构
CExpandVector::~CExpandVector()
{
	cout << "~~" << endl;
	vector<int>::iterator v = m_vector.begin();
	while (v != m_vector.end()) {
		cout << "value of v = " << *v << endl;
		v++;
	}
}
//插入指定位置（越界？）
int CExpandVector::MyInsert(int iPlace, int iVal)
{
	if (iPlace > m_vector.size())//越界返回0
	{
		return 0;
	}
	//正常情况下
	vector<int>::iterator iter = m_vector.begin();
	while (--iPlace)
	{
		iter++;
	}
	m_vector.insert(iter, iVal);//insert
	return 1;
}
//删除单个指定位置(越界？)
int CExpandVector::MyEraseAt(int iPlace)
{
	if (iPlace > m_vector.size())//越界返回0
	{
		return 0;
	}
	//正常情况下
	vector<int>::iterator iter = m_vector.begin();
	while (--iPlace)
	{
		iter++;
	}
	m_vector.erase(iter);//erase
	return 1;
}
//删除单个指定值
int CExpandVector::MyEraseVal(int iVal)
{
	vector<int>::iterator iter = m_vector.erase(remove(begin(m_vector), end(m_vector), iVal), end(m_vector));//指定值
	return 1;
}
//修改指定位置（越界?）
int CExpandVector::MyChange(int iPlace, int iVal)
{
	if (iPlace > m_vector.size())//越界返回0
	{
		return 0;
	}
	//正常情况下
	MyEraseAt(iPlace);
	MyInsert(iPlace, iVal);
	return 1;
}
//获取指定位置的值(越界？)
int CExpandVector::MyGetAt(int iPlace)
{
	if (iPlace > m_vector.size())//越界返回0
	{
		cout << "It's transboundary." << endl;
		return -11111;
	}
	//正常情况下
	vector<int>::iterator iter = m_vector.begin();
	while (--iPlace)
	{
		iter++;
	}
	return *iter;
}
