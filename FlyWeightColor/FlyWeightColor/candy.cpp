#include"candy.h"
//ÌÇ¹û
CCandy::CCandy()
{
}

CCandy::~CCandy()
{
}

//ÑÕÉ«
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