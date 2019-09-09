#include"candyFactory.h"
#include"candy.h"
#include<iostream>

using namespace std;

CCandyFactory::CCandyFactory()
{
	string szBlue = "blue";
	CCandy* pBlueCandy = new CColore(szBlue);
	m_vecCandy.push_back(pBlueCandy);

	string szRed = "red";
	CCandy* pRedCandy = new CColore(szRed);
	m_vecCandy.push_back(pRedCandy);

	string szBlack = "black";
	CCandy* pBlackCandy = new CColore(szBlack);
	m_vecCandy.push_back(pBlackCandy);

}

CCandyFactory::~CCandyFactory()
{
}

CCandy* CCandyFactory::GetCandyColor(int key)
{
	return m_vecCandy.at(key);
}
