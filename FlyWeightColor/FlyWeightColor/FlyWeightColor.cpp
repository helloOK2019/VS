#include <iostream>
#include"candy.h"
#include"candyFactory.h"

using namespace std;


int main()
{
	CCandyFactory* pCandyFactory = new CCandyFactory();
	
	//获取第一个糖的颜色
	cout<<pCandyFactory->GetCandyColor(1);





	return 0;
}

