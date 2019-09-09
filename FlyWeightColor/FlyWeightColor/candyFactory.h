#ifndef _CANDYFACTORY_H_
#define _CANDYFACTORY_H_
#include<vector>
#include"candy.h"
class CCandyFactory
{
public:
	CCandyFactory();
	~CCandyFactory();
	CCandy* GetCandyColor(int key);
private:
	std::vector<CCandy*> m_vecCandy;

};

#endif // !_CANDYFACTORY_H_
