#include"Observer.h"
#include<iostream>
#include<string>

using namespace std;
//����۲���
IObserver::IObserver()
{
}
IObserver::IObserver(string szName)
{
}

IObserver::~IObserver()
{
}

void IObserver::Update()
{
}
//����۲���
CConcreteObserver::CConcreteObserver()
{
}
CConcreteObserver::CConcreteObserver(string szName)
{
	m_szName = szName;
}

CConcreteObserver::~CConcreteObserver()
{
}
void CConcreteObserver::SetName(string szName)
{
	m_szName = szName;
}
string CConcreteObserver::GetName()
{
	return m_szName;
}
//����
void CConcreteObserver::Update()
{
	cout << m_szName <<" has Updated." << endl;
}