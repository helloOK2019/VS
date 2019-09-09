#include<iostream>
#include"Client.h"
#include"winsock2.h"
#pragma comment(lib,"ws2_32.lib")
using namespace std;

#define MAXSIZE 1024
typedef struct SendBox
{
	char pszMessBuff[MAXSIZE];
	Client* pMessClient;
	int* piEndFlag;
	//HANDLE* sendEvent;
}SEND_BOX;

HANDLE g_hSendEvent;
HANDLE g_hRecvEvent;
DWORD WINAPI ConeThread(LPVOID IpParameter);
DWORD WINAPI SendThread(LPVOID IpParameter);
DWORD WINAPI RecvThread(LPVOID IpParameter);

int main()
{
	int Port = 60000;
	char szIp[] = "127.0.0.1";
	//Client pMyClient(Port, szIp);
	Client* pMyClient = new Client(Port, szIp);
	pMyClient->createSocket();//完成套接字初始化、绑定等工作

	HANDLE coneThread = CreateThread(NULL, 0, ConeThread, (LPVOID)pMyClient, 0, NULL);//创建连接进程
	WaitForSingleObject(coneThread, INFINITE);
	CloseHandle(coneThread);

	int* piEndFlag = new int;
	*piEndFlag = 1;
	SEND_BOX sendBox = { {0},NULL, piEndFlag };
	HANDLE hSendThread = CreateThread(NULL, 0, SendThread, &sendBox, 0, NULL);//创建发送线程
	HANDLE hRecvThread = CreateThread(NULL, 0, RecvThread, (LPVOID)& pMyClient, 0, NULL);//创建接收线程
	//HANDLE sendEvent = CreateEvent(NULL, false, false, NULL);
	g_hSendEvent = CreateEvent(NULL, false, false, NULL);
	g_hRecvEvent = CreateEvent(NULL, false, false, NULL);
	while (1)
	{
		cin >> sendBox.pszMessBuff;
		sendBox.pMessClient = pMyClient;
		SetEvent(g_hSendEvent);
		Sleep(10);//piEndFlag 可能还没被子线程改写，if语句就被执行了，所以加个时延
		if (*piEndFlag == 0)
		{
			cout << "main break" << endl;
			SetEvent(g_hRecvEvent);
			break;
		}
		//sendBox.sendEvent = &sendEvent;
	}
	CloseHandle(g_hSendEvent);
	CloseHandle(hSendThread);
	CloseHandle(hRecvThread);
	//pMyClient->closeSocket();
	endFunc();
	return 0;
}
DWORD WINAPI ConeThread(LPVOID IpParameter)
{
	Client* pClient = (Client*)IpParameter;
	while (pClient->clientConnect());//完成连接后跳出
	return 0;
}

DWORD WINAPI SendThread(LPVOID IpParameter)
{
	SEND_BOX* pMessBox = (SEND_BOX*)IpParameter;
	Client* pClient = pMessBox->pMessClient;
	char* pszMessBuff = pMessBox->pszMessBuff;
	while (1)
	{
		//DWORD  dw = WaitForSingleObject(pMessBox->sendEvent, INFINITE);
		DWORD  dwRet = WaitForSingleObject(g_hSendEvent, INFINITE);
		switch (dwRet) {
		case WAIT_OBJECT_0:
			//发送数据
			//pClient->clientSend(pszMessBuff);
			*(pMessBox->piEndFlag) = pClient->clientSend(pszMessBuff);
			memset(pszMessBuff, 0, sizeof(pszMessBuff));
			break;
		case WAIT_TIMEOUT:
			cout << "超时" << endl;
			break;
		case WAIT_FAILED:
			cout << "函数发生错误" << endl;
			break;
		}
		//收到退出命令
		if (*(pMessBox->piEndFlag) == 0)
		{
			break;
		}
	}
	cout << "sendThread has ended" << endl;
	return 0;
}

DWORD WINAPI RecvThread(LPVOID IpParameter)
{
	Client* pClient = (Client*)IpParameter;
	while (1)
	{
		pClient->clientRecv();
		DWORD  dwRet = WaitForSingleObject(g_hRecvEvent, INFINITE);
		if (dwRet == WAIT_OBJECT_0)
		{
			cout << "recvThread has ended" << endl;
			break;
		}
	}
	return 0;
}