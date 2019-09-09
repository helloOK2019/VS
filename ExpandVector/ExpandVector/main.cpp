#include <iostream>
#include<vector>
#include"ExpandVector.h"
using namespace std;

int main()
{
	CExpandVector objMyVector;
	//删除第五个数
	int iTemp = 5;
	if (objMyVector.MyEraseAt(iTemp))//根据返回值判断删除情况
	{
		cout <<"The 5th number erase secceeded" << endl;
	}
	else
	{
		cout << "transboundary" << endl;
	}

	//第五个数字插入666
	cout << "insert 666 at 5th ";
	if (objMyVector.MyInsert(iTemp, 666))
	{
		cout << "secceeded" << endl;
	}
	else
	{
		cout << "transboundary" << endl;
	}
	
	//第四个数字改成888
	if (objMyVector.MyChange(4, 888))
	{
		cout << "The 4th number change succeeded" << endl;
	}
	else
	{
		cout << "transboundary" << endl;
	}
	//第六个数是
	cout << "The 6th number this " << objMyVector.MyGetAt(6) << endl;

	cout << "main end" << endl;
}