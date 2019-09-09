//享元模式
//彩色糖果工厂
//2019/08/05
#include <iostream>
#include"candy.h"
#include"candyFactory.h"

using namespace std;


int main()
{
	CCandyFactory* pCandyFactory = new CCandyFactory();

	CCandy* pCandyTemp = NULL;
	//获取第二个糖的颜色
	pCandyTemp = pCandyFactory->GetCandyColor(1);
	cout << "The color of candy is " << pCandyTemp->GetCandyColor() << endl;
	//第一个
	pCandyTemp = pCandyFactory->GetCandyColor(0);
	cout << "The color of candy is " << pCandyTemp->GetCandyColor() << endl;
	//第三个
	pCandyTemp = pCandyFactory->GetCandyColor(2);
	cout << "The color of candy is " << pCandyTemp->GetCandyColor() << endl;
	

	//创建工厂
	//客户端保存抽象享元对象
	//通过传参（外部状态）访问具体享元（糖果颜色）


	return 0;
}

