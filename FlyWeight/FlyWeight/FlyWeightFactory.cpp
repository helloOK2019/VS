#include"FlyWeightFactory.h"
#include"FlyWeight.h"
#include<iostream>
using  namespace std;
FlyWeightFactory::FlyWeightFactory()
{
	FlyWeight* tmp = new ConcreteFlyWeight();//工厂创建时
	m_vec.push_back(tmp);
}

FlyWeightFactory::~FlyWeightFactory()
{
	FlyWeight* tmp = m_vec.at(0);
	delete tmp;
	tmp = NULL;
}
//获取具体享元
FlyWeight* FlyWeightFactory::GetFlyWeight(int key)
{
	return m_vec.at(key);
}


