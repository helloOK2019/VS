#include"candy.h"
//�ǹ�
CCandy::CCandy()
{
}

CCandy::~CCandy()
{
}

//��ɫ
CColore::CColore(string szColor)
{
	m_szColore = szColor;
}

CColore::~CColore()
{
}

string CColore::GetCandyColor()
{
	return m_szColore;
}