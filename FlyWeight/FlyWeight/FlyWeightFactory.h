#ifndef _FLYWEIGHTFACTORY_H_
#define _FLYWEIGHTFACTORY_H_
#include<vector>
#include"FlyWeight.h"
using namespace std;

class FlyWeightFactory
{
public:
	FlyWeightFactory();
	~FlyWeightFactory();
	FlyWeight* GetFlyWeight(int key);//��ȡ������Ԫ
private:
	vector<FlyWeight*> m_vec;//�ڹ����ṩ
};

#endif // !_FLYWEIGHTFACTORY
