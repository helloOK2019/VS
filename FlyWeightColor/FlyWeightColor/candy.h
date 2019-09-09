#ifndef _CANDY_H_
#define _CANDY_H_
#include<iostream>
using namespace std;
//ÌÇ¹û
class CCandy
{
public:
	CCandy();
	~CCandy();
	virtual string GetCandyColor() = 0;

private:

};
//ÑÕÉ«
class CColore : public CCandy
{
public:
	CColore(string szColor);
	~CColore();
	string GetCandyColor();
private:
	string m_szColore;
};

#endif // !_CANDY_H_
