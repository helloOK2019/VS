#include"FlyWeight.h"
#include<iostream>
using namespace std;
//抽象部分
FlyWeight::FlyWeight()
{
}

FlyWeight::~FlyWeight()
{
}

void FlyWeight::Operation()
{
}
//具体部分
ConcreteFlyWeight::ConcreteFlyWeight()
{
}

ConcreteFlyWeight::~ConcreteFlyWeight()
{
}

void ConcreteFlyWeight::Operation()
{
	cout << "ConcreteFlyWeight" << endl;
}