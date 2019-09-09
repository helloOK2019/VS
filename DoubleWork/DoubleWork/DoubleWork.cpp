#include<iostream>
#include<Windows.h>//For HANDLE
#include <PROCESS.H>//For beginthreadex
#include<vector>
using namespace std;

vector<int> g_iVec;
HANDLE g_hWriteEvent;
HANDLE g_hWorkEvent;

//写线程
unsigned _stdcall WriteThread(void* ptr)
{
	while (true)
	{
		DWORD  dwRet = WaitForSingleObject(g_hWriteEvent, INFINITE);
		g_iVec.push_back(*(int*)ptr);
		cout << "WriteThread done" << endl;
		SetEvent(g_hWorkEvent);//加百
	}
	return 0;
}

//加百
unsigned _stdcall WorkThread(void* ptr)
{
	while (true)
	{
		DWORD  dwRet = WaitForSingleObject(g_hWorkEvent, INFINITE);
		int iLast = g_iVec.back();
		g_iVec.pop_back();
		g_iVec.push_back(iLast + 100);

		iLast = g_iVec.back();
		cout << "WorkThread done. iLast: " << iLast << endl;
	}
	return 0;
}


int main()
{ 
	int iTemp = 0;
	HANDLE h1 = (HANDLE)_beginthreadex(0, 0, WriteThread, (LPVOID*)&iTemp, 0, 0);
	HANDLE h2 = (HANDLE)_beginthreadex(0, 0, WorkThread, NULL, 0, 0);

	g_hWriteEvent = CreateEvent(NULL, false, false, NULL);
	g_hWorkEvent = CreateEvent(NULL, false, false, NULL);

	while (1)
	{
		cout << "cin -123456 to end: " << endl;
		cin >> iTemp;
		if (iTemp == (-123456))
		{
			cout << "bye bye" << endl;
			break;
		}
		else
		{
			SetEvent(g_hWriteEvent);//写入
		}
		Sleep(10);
	}

	return 0;
}