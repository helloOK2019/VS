#include<iostream>
#include"winsock2.h"
#include <WS2tcpip.h>
using namespace std;

#define PORT 60000
#define MSGSIZE 2000
#pragma comment(lib, "ws2_32.lib") 

int     g_iTotalConn = 0;//总连接数
SOCKET g_CliSocketArr[FD_SETSIZE];//sock数组
DWORD WINAPI WorkerThread(LPVOID lpParameter);//工作线程

int main()
{

}