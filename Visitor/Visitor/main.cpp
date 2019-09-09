//https://blog.csdn.net/liang19890820/article/details/79364406
#include"element.h"//元素
#include"object_structure.h"//数据结构
#include"visitor.h"//访问者

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif

int main()
{
	City* city = new City();

	// 景点 - 钟楼、 白楼
	IPlace* bellTower = new BellTower();
	IPlace* whilteTower = new WhilteTower();

	// 访问者 - 游客、清洁工
	IVisitor* tourist = new Tourist();
	IVisitor* cleaner = new Cleaner();

	// 添加景点//每添加一个景点需要对应添加访问方法
	city->Attach(bellTower);
	city->Attach(whilteTower);

	// 接受访问
	city->Accept(tourist);
	city->Accept(cleaner);

	SAFE_DELETE(cleaner);
	SAFE_DELETE(tourist);
	SAFE_DELETE(whilteTower);
	SAFE_DELETE(bellTower);
	SAFE_DELETE(city);

	return 0;
}
