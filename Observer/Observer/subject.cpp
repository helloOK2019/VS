#include"Subject.h"
#include"Observer.h"
#include<iostream>
#include<vector>
#include <algorithm>//for begin end

using namespace std;

//抽象主题
ISubject::ISubject()
{
}

ISubject::~ISubject()
{
}

void ISubject::Attach(IObserver *obj)
{
}

void ISubject::Delete(IObserver *obj)
{
}

//具体主题
CConcreteSubject::CConcreteSubject()
{
}

CConcreteSubject::~CConcreteSubject()
{
}

void CConcreteSubject::Attach(IObserver *obj)
{
	m_vecObj.push_back(obj);
}

void CConcreteSubject::Delete(IObserver *obj)
{
	m_vecObj.erase(remove(begin(m_vecObj), end(m_vecObj), obj), end(m_vecObj));
}

void CConcreteSubject::Notify()
{
	vector<IObserver*>::iterator objIter = m_vecObj.begin();
	while (objIter!=m_vecObj.end())
	{
		(**objIter).Update();
		objIter++;
	}
}