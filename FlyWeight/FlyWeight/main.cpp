#include<iostream>
#include"FlyWeight.h"
#include"FlyWeightFactory.h"
using namespace std;

int main()
{
	FlyWeightFactory* objFactory = new FlyWeightFactory();//创建工厂

	FlyWeight* pFlyWeight = objFactory->GetFlyWeight(0);//获取一个享元
	pFlyWeight->Operation();//执行动作
	return 0;
}