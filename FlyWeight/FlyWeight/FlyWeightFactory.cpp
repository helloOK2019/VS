#include"FlyWeightFactory.h"
#include"FlyWeight.h"
#include<iostream>
using  namespace std;
FlyWeightFactory::FlyWeightFactory()
{
	FlyWeight* tmp = new ConcreteFlyWeight();//��������ʱ
	m_vec.push_back(tmp);
}

FlyWeightFactory::~FlyWeightFactory()
{
	FlyWeight* tmp = m_vec.at(0);
	delete tmp;
	tmp = NULL;
}
//��ȡ������Ԫ
FlyWeight* FlyWeightFactory::GetFlyWeight(int key)
{
	return m_vec.at(key);
}


