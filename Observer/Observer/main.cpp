#include<iostream>
#include"Observer.h"
#include"Subject.h"
using namespace std;

int main()
{
	string szHello = "hello";
	string szOk = "OK";
	CConcreteSubject* pSubject = new CConcreteSubject();
	CConcreteObserver* pObserver = new CConcreteObserver(szHello);
	pSubject->Attach(pObserver);
	pObserver = new CConcreteObserver(szOk);
	pSubject->Attach(pObserver);

	pSubject->Notify();


	return	0;
}