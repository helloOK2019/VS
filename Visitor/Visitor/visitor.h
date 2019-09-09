#ifndef _VISITOR_H_
#define _VISITOR_H_
//访问者
#include"element.h"
#include<iostream>
using namespace std;
class BellTower;
class WhilteTower;

class IVisitor
{
public:
	virtual ~IVisitor();
	virtual void Visit(BellTower* bellTower) = 0;
	virtual void Visit(WhilteTower* whilteTower) = 0;

private:

};

IVisitor::~IVisitor()
{
}

//游客
class Tourist : public IVisitor
{
public:
	Tourist();
	~Tourist();
	void Visit(BellTower* bellTower)override;
	void Visit(WhilteTower* whilteTower)override;

private:

};

Tourist::Tourist(){}

Tourist::~Tourist(){}

void Tourist::Visit(BellTower* bellTower)
{
	cout << "I'm visiting the BellTower!" << endl;
}

void Tourist::Visit(WhilteTower* whilteTower)
{
	cout << "I'm visiting the WhilteTower!" << endl;
}

//清洁工
class Cleaner : public IVisitor
{
public:
	Cleaner();
	~Cleaner();
	void Visit(BellTower* bellTower)override;
	void Visit(WhilteTower* whilteTower)override;

private:

};

Cleaner::Cleaner(){}

Cleaner::~Cleaner(){}

void Cleaner::Visit(BellTower* bellTower)
{
	cout << "I'm cleaning the BellTower!" << endl;
}

void Cleaner::Visit(WhilteTower* whilteTower)
{
	cout << "I'm cleaning the WhilteTower!" << endl;
}
#endif // !_VISITOR_H_
