#ifndef _ELEMENT_H_
#define _ELEMENT_H_
//Ԫ��
#include<iostream>
#include"visitor.h"
using namespace std;

class IVisitor;//Ԥ����

//����Ԫ��

//����ӿ�
class IPlace
{
public:
	virtual ~IPlace();
	virtual void Accept(IVisitor* visitor) = 0;

private:

};

IPlace::~IPlace()
{
}

//��¥
class BellTower : public IPlace
{
public:
	~BellTower();
	void Accept(IVisitor* visitor) override;

private:

};

BellTower::~BellTower(){}

void BellTower::Accept(IVisitor* visitor)
{
	cout << "BellTower is accepting visitor." << endl;
	visitor->Visit(this);
}

//����
class WhilteTower : public IPlace
{
public:
	~WhilteTower();
	void Accept(IVisitor* visitor) override;

private:

};

WhilteTower::~WhilteTower(){}

void WhilteTower::Accept(IVisitor* visitor)
{
	cout << "WhilteTower is accepting visitor." << endl;
	visitor->Visit(this);
}
#endif // !_ELEMENT_H_
