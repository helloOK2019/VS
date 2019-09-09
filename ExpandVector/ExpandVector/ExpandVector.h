#ifndef _ExpandVecto_H_
#define _ExpandVecto_H_
//vector<int>
#include<vector>
using namespace std;

class CExpandVector
{
public:
	//Q1如何设计构造函数，这个卡了挺久（不定参数函数结合vector初始化）
	CExpandVector();//初始化
	~CExpandVector();//析构
	
	int MyEraseAt(int iPlace);//删除指定位置的元素
	int MyEraseVal(int iVal);//删除指定值
	int MyInsert(int iPlace, int iVal);//指定位置插入指定值
	int MyChange(int iPlace, int iVal);//指定位置修改指定值
	int MyGetAt(int iPlace);//获取指定位置的值
private:
	vector<int> m_vector;
};

#endif // !_ExpandVecto_H_