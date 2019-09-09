#ifndef _OBSERVER_H_
#define _OBSERVER_H_
#include<string>
using namespace std;
//����۲���
class IObserver
{
public:
	IObserver();
	IObserver(string szName);
	virtual ~IObserver();
	void virtual Update();

private:
	
};

//����۲���
class CConcreteObserver : public IObserver
{
public:
	CConcreteObserver();
	CConcreteObserver(string szName);
	~CConcreteObserver();
	void Update();
	void SetName(string szName);
	string GetName();
private:
	string m_szName;
};

#endif // !_OBSERVER_H_
