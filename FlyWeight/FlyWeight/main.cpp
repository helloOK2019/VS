#include<iostream>
#include"FlyWeight.h"
#include"FlyWeightFactory.h"
using namespace std;

int main()
{
	FlyWeightFactory* objFactory = new FlyWeightFactory();//��������

	FlyWeight* pFlyWeight = objFactory->GetFlyWeight(0);//��ȡһ����Ԫ
	pFlyWeight->Operation();//ִ�ж���
	return 0;
}