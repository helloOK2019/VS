//给出矩形对角线坐标，获取矩形内（包括边上）的所有坐标（只算整形值）
#include <iostream>
#include<Windows.h>
#include<conio.h>
using namespace std;

void Clean(HANDLE handle, COORD* pos);
void MarkPoint(int iBeginPointx, int iBeginPointy, int iEndPointx, int iEndPointy);
void GetCoordinate(int iBeginPointx, int iBeginPointy, int iEndPointx, int iEndPointy);
//int TestFunc(int iBeginPointx, int iBeginPointy, int iEndPointx, int iEndPointy, int x, int y);

int main()
{
	int a, b, c, d;
	while (1)
	{
		cout << "beginPoint:";
		cin >> a >> b;
		cout << "endPoint:";
		cin >> c >> d;
		GetCoordinate(a, b, c, d);
		MarkPoint(a, b, c, d);
	}
}

void Clean(HANDLE handle, COORD* pos)
{
	for (int i = 2; i <50; i++)
	{
		for (int j = 0; j < 70; j++)
		{
			pos->X = j;
			pos->Y = i;
			SetConsoleCursorPosition(handle, *pos);
			cout << " " << endl;
		}
	}
}
void MarkPoint(int iBeginPointx, int iBeginPointy, int iEndPointx, int iEndPointy)
{
	HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);    //获得标准输出设备句柄  
	CONSOLE_CURSOR_INFO cci;        //定义光标信息结构体  
	GetConsoleCursorInfo(handle_out, &cci);     //获得当前光标信息
	cci.bVisible = true;       //设置光标为不可见  
	SetConsoleCursorInfo(handle_out, &cci);
	COORD pos;
	pos.X = iBeginPointx;
	pos.Y = iBeginPointy + 2;
	SetConsoleCursorPosition(handle_out, pos);
	cout << "1" << endl;
	pos.X = iEndPointx;
	pos.Y = iEndPointy + 2;
	SetConsoleCursorPosition(handle_out, pos);
	cout << "2" << endl;
	pos.X = 0;
	pos.Y = 0;
	SetConsoleCursorPosition(handle_out, pos);
}
void GetCoordinate(int iBeginPointx, int iBeginPointy, int iEndPointx, int iEndPointy)
{
	int iMaxValX = iBeginPointx > iEndPointx ? iBeginPointx : iEndPointx;
	int iMinValX = iBeginPointx < iEndPointx ? iBeginPointx : iEndPointx;
	int iMaxValY = iBeginPointy > iEndPointy ? iBeginPointy : iEndPointy;
	int iMinValY = iBeginPointy < iEndPointy ? iBeginPointy : iEndPointy;
	if (iMaxValX == iMinValX && iMaxValY == iMinValY)//判断点
	{
		cout << "It is just a point" << endl;
	}
	else//矩阵
	{
		HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);    //获得标准输出设备句柄  
		CONSOLE_CURSOR_INFO cci;        //定义光标信息结构体  
		GetConsoleCursorInfo(handle_out, &cci);     //获得当前光标信息
		cci.bVisible = true;       //设置光标为不可见  
		SetConsoleCursorInfo(handle_out, &cci);
		COORD pos;
		Clean(handle_out, &pos);
		for (int i = iMinValX; i <= iMaxValX; i++)
		{
			for (int j = iMinValY; j <= iMaxValY; j++)
			{
				pos.X = i;
				pos.Y = j + 2;
				SetConsoleCursorPosition(handle_out, pos);
				cout << "0" << endl;
				//cout << "(" << i << ", " << j << ") ";
			}
			cout << endl;
		}
	}
}
