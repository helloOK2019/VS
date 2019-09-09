////////////////////////////////////////
//
//
//
////////////////////////////////////////
//Q1:怎么保证读出队列元素的时候队列已经有写入元素
#include <iostream>
#include <windows.h>
#include <PROCESS.H>
#include<queue>

using namespace std;

queue<int> g_queue;
CRITICAL_SECTION g_csLock1;
CRITICAL_SECTION g_csLock2;
unsigned _stdcall thread1(void* ptr)
{
	for (int i = 1; i <= 20; i++)
	{
		EnterCriticalSection(&g_csLock1);
		cout << "thread 1-->push\t" ;
		cout << i << endl;
		g_queue.push(i);
		Sleep(50);
		LeaveCriticalSection(&g_csLock1);
	}
	return 0;
}

unsigned _stdcall thread2(void* ptr)
{
	for (int i = 21; i <= 40; i++)
	{
		EnterCriticalSection(&g_csLock1);
		cout << "therad 2-->push\t";
		cout << i << endl;
		g_queue.push(i);
		Sleep(60);
		LeaveCriticalSection(&g_csLock1);
	}
	return 0;
}

unsigned _stdcall thread3(void* ptr)
{
	for (int i = 1; i <= 20; i++)
	{
		if (g_queue.size() > 0)
		{
			EnterCriticalSection(&g_csLock1);
			cout << "thread 3-->pop\t";
			cout << g_queue.front() << endl;
			g_queue.pop();
			Sleep(40);
			LeaveCriticalSection(&g_csLock1);
		}
		else
		{
			Sleep(20);
		}
	}
	return 0;
}

unsigned _stdcall thread4(void* ptr)
{
	for (int i = 1; i <= 20; i++)
	{
		if (g_queue.size() > 0)
		{
			EnterCriticalSection(&g_csLock1);
			cout << "thread 4-->pop\t";
			cout << g_queue.front() << endl;
			g_queue.pop();
			Sleep(60);
			LeaveCriticalSection(&g_csLock1);
		}
		else
		{
			Sleep(20);
		}
	}
	return 0;
}

int main()
{

	//初始化临界区
	InitializeCriticalSection(&g_csLock1);

	HANDLE h1 = (HANDLE)_beginthreadex(0, 0, thread1, NULL, 0, 0);
	HANDLE h2 = (HANDLE)_beginthreadex(0, 0, thread2, NULL, 0, 0);
	HANDLE h3 = (HANDLE)_beginthreadex(0, 0, thread3, NULL, 0, 0);
	HANDLE h4 = (HANDLE)_beginthreadex(0, 0, thread4, NULL, 0, 0);

	::WaitForSingleObject(h1, INFINITE);
	CloseHandle(h1);
	::WaitForSingleObject(h2, INFINITE);
	CloseHandle(h2);
	::WaitForSingleObject(h3, INFINITE);
	CloseHandle(h3);
	::WaitForSingleObject(h4, INFINITE);
	CloseHandle(h4);

	//清理资源
	DeleteCriticalSection(&g_csLock1);
	DeleteCriticalSection(&g_csLock2);

	return 0;
}