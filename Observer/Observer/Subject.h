#ifndef _SUBJECT_H_
#define _SUBJECT_H_
#include"Observer.h"
#include<vector>

//��������
class ISubject
{
public:
	ISubject();
	~ISubject();
	virtual void Attach(IObserver *obj);
	virtual void Delete(IObserver *obj);
private:
	
};

//��������
class CConcreteSubject : public ISubject
{
public:
	CConcreteSubject();
	~CConcreteSubject();
	void Attach(IObserver *obj);
	void Delete(IObserver *obj);
	void Notify();

private:
	std::vector<IObserver*> m_vecObj;
};

#endif // !_SUBJECT_H_
