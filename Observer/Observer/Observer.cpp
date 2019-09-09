#include"Observer.h"
#include<iostream>
#include<string>

using namespace std;
//抽象观察者
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
//具体观察者
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
//更新
void CConcreteObserver::Update()
{
	cout << m_szName <<" has Updated." << endl;
}