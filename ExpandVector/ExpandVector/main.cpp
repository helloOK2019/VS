#include <iostream>
#include<vector>
#include"ExpandVector.h"
using namespace std;

int main()
{
	CExpandVector objMyVector;
	//ɾ���������
	int iTemp = 5;
	if (objMyVector.MyEraseAt(iTemp))//���ݷ���ֵ�ж�ɾ�����
	{
		cout <<"The 5th number erase secceeded" << endl;
	}
	else
	{
		cout << "transboundary" << endl;
	}

	//��������ֲ���666
	cout << "insert 666 at 5th ";
	if (objMyVector.MyInsert(iTemp, 666))
	{
		cout << "secceeded" << endl;
	}
	else
	{
		cout << "transboundary" << endl;
	}
	
	//���ĸ����ָĳ�888
	if (objMyVector.MyChange(4, 888))
	{
		cout << "The 4th number change succeeded" << endl;
	}
	else
	{
		cout << "transboundary" << endl;
	}
	//����������
	cout << "The 6th number this " << objMyVector.MyGetAt(6) << endl;

	cout << "main end" << endl;
}