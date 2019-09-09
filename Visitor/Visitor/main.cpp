//https://blog.csdn.net/liang19890820/article/details/79364406
#include"element.h"//Ԫ��
#include"object_structure.h"//���ݽṹ
#include"visitor.h"//������

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif

int main()
{
	City* city = new City();

	// ���� - ��¥�� ��¥
	IPlace* bellTower = new BellTower();
	IPlace* whilteTower = new WhilteTower();

	// ������ - �ο͡���๤
	IVisitor* tourist = new Tourist();
	IVisitor* cleaner = new Cleaner();

	// ��Ӿ���//ÿ���һ��������Ҫ��Ӧ��ӷ��ʷ���
	city->Attach(bellTower);
	city->Attach(whilteTower);

	// ���ܷ���
	city->Accept(tourist);
	city->Accept(cleaner);

	SAFE_DELETE(cleaner);
	SAFE_DELETE(tourist);
	SAFE_DELETE(whilteTower);
	SAFE_DELETE(bellTower);
	SAFE_DELETE(city);

	return 0;
}
