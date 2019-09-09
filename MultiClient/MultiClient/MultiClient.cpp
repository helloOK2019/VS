////////////////////////////////////////
//
//
//
////////////////////////////////////////
//实现客户端类
//
#include <iostream>
#include <WS2tcpip.h>
#include <winsock2.h>
using namespace std;
#pragma comment(lib,"ws2_32.lib") //以静态方式加载库
#define IP "192.168.211.109"		  //IP地址
#define PORT 60000				  //端口号  
DWORD WINAPI SockSend(LPVOID lpParameter);
DWORD WINAPI SockRecv(LPVOID lpParameter);
SOCKET sock_client;
HANDLE sendEvent;
char sendBuf[1024];
int main()
{
	WSADATA wsaData;
	WORD sockVersion = MAKEWORD(2, 0);//组织版本号数据

	//完成对WinSock的初始化
	if (WSAStartup(sockVersion, &wsaData))
	{
		cout << "Failed to retrive socket version." << endl;
		return 0;
	}

	//创建TCP连接
	sock_client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == sock_client)
	{
		cout << "Invalid socket." << endl;
		//终止Winsock 2 DLL (Ws2_32.dll) 的使用.
		WSACleanup();
		return 0;
	}
	sockaddr_in addr_sev;
	addr_sev.sin_family = AF_INET;
	addr_sev.sin_port = htons(PORT);
	//addr_sev.sin_addr.s_addr = inet_addr(IP);
	inet_pton(AF_INET, IP, &addr_sev.sin_addr);
	//连接服务器
	if (SOCKET_ERROR == connect(sock_client, (sockaddr*)& addr_sev, sizeof(addr_sev)))
	{
		cout << "Failed to connect." << endl;
		//终止Winsock 2 DLL (Ws2_32.dll) 的使用.
		WSACleanup();
		return 0;
	}

	//创建收线程
	HANDLE rThread = CreateThread(NULL, 0, SockRecv, NULL, 0, NULL);
	CloseHandle(rThread);

	//创建发线程
	HANDLE sThread = CreateThread(NULL, 0, SockSend, NULL, 0, NULL);
	CloseHandle(sThread);

	//创建事件
	sendEvent = CreateEvent(NULL, false, false, NULL);
	while (1)
	{
		//输入数据后，通过事件的方式告知发送进程
		cin >> sendBuf;
		SetEvent(sendEvent);
	}
	CloseHandle(sendEvent);
	closesocket(sock_client);

	//终止Winsock 2 DLL (Ws2_32.dll) 的使用
	WSACleanup();
	system("PAUSE");
}

DWORD WINAPI SockSend(LPVOID lpParameter)
{
	DWORD sendSize;
	DWORD dw;
	memset(sendBuf, 0, 1024);
	while (1)
	{
		//等待发送事件
		dw = WaitForSingleObject(sendEvent, INFINITE);
		switch (dw) {
		case WAIT_OBJECT_0:
			//发送数据
			sendSize = send(sock_client, sendBuf, strlen(sendBuf), 0);
			memset(sendBuf, 0, sendSize);
			break;
		case WAIT_TIMEOUT:
			cout << "超时" << endl;
			break;
		case WAIT_FAILED:
			cout << "函数发生错误" << endl;
			break;
		}
	}
	return 0;
};

DWORD WINAPI SockRecv(LPVOID lpParameter)
{
	char recvBuf[1024];
	DWORD recvSize;
	memset(recvBuf, 0, 1024);
	while (1)
	{
		//把接受的数据显示出来
		recvSize = recv(sock_client, recvBuf, 128, 0);
		cout << "Recv=" << recvBuf << endl;
		memset(recvBuf, 0, recvSize);
	}
	return 0;
};