#ifndef _ExpandVecto_H_
#define _ExpandVecto_H_
//vector<int>
#include<vector>
using namespace std;

class CExpandVector
{
public:
	//Q1�����ƹ��캯�����������ͦ�ã����������������vector��ʼ����
	CExpandVector();//��ʼ��
	~CExpandVector();//����
	
	int MyEraseAt(int iPlace);//ɾ��ָ��λ�õ�Ԫ��
	int MyEraseVal(int iVal);//ɾ��ָ��ֵ
	int MyInsert(int iPlace, int iVal);//ָ��λ�ò���ָ��ֵ
	int MyChange(int iPlace, int iVal);//ָ��λ���޸�ָ��ֵ
	int MyGetAt(int iPlace);//��ȡָ��λ�õ�ֵ
private:
	vector<int> m_vector;
};

#endif // !_ExpandVecto_H_