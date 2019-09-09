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
	FlyWeight* GetFlyWeight(int key);//获取具体享元
private:
	vector<FlyWeight*> m_vec;//在工厂提供
};

#endif // !_FLYWEIGHTFACTORY
