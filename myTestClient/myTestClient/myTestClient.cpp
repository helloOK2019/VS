////////////////////////////////////////
//Author:hello_OK
//Created:2019/07/17
//Describe:简易客户端
////////////////////////////////////////

#include <iostream>
#include <WS2tcpip.h>
#include <string>  
#include"winsock2.h"
#pragma comment(lib,"ws2_32.lib")
using namespace std;

SOCKET clnSocket;//连接成功后的套接字
HANDLE	buffMutex;//信号量句柄

int main()
{
	//1.初始化套接字
	WSADATA wsd;
	if (WSAStartup(MAKEWORD(2, 2), &wsd) != 0)
	{
		cout << "WSAStartup failed!" << endl;
		return 1;
	}
	else
	{
		cout << "1.WSAStartup succeeded!" << endl;
	}

	//创建套接字
	clnSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == clnSocket)
	{
		cout << "socket failed!" << endl;
		WSACleanup();
		return 1;
	}
	else
	{
		cout << "2.socket succeeded!" << endl;
	}

	//绑定套接字
	sockaddr_in addrSrv;
	memset(&addrSrv, 0, sizeof(addrSrv));
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons((short)4999);
	inet_pton(AF_INET, "127.0.0.1", &addrSrv.sin_addr);
	/*
		addrSrv.sin_addr.s_addr = inet_addr("127.0.0.1");
		为什么在这里inet_addr不能使用
	*/

	//发起连接
	int retVal = connect(clnSocket, (SOCKADDR*)& addrSrv, sizeof(SOCKADDR));
	if (SOCKET_ERROR == retVal)
	{
		cout << "connect failed!" << endl;
	}
	else
	{
		cout << "3.connect succeeded!" << endl;
	}
	/*connect函数返回什么(用于异常检测)，怎么查看文档？-->F1*/
	/*这里需要做一个独立线程完成连接吗？-->不需要,主程序只做一件事*/
	
	//声明收发两个线程
	DWORD WINAPI SendThread(LPVOID IpParameter);
	DWORD WINAPI RecvThread(LPVOID IpParameter);

	//创建收发两个线程
	HANDLE sendThread = CreateThread(NULL, 0, SendThread, NULL, 0, NULL);
	HANDLE recvThread = CreateThread(NULL, 0, RecvThread, NULL, 0, NULL);

	WaitForSingleObject(sendThread, INFINITE);


	//关闭
	closesocket(clnSocket);
	CloseHandle(sendThread);
	CloseHandle(recvThread);
	CloseHandle(buffMutex);
	WSACleanup();

}


DWORD WINAPI SendThread(LPVOID IpParameter)
{
	while (1) {
		string talk;
		getline(cin, talk);
		WaitForSingleObject(buffMutex, INFINITE);     // P（资源未被占用）    
		if ("quit" == talk) {
			talk.push_back('\0');
			//send(sockClient, talk.c_str(), talk.size(), 0);  
			send(clnSocket, talk.c_str(), 200, 0);
			break;
		}
		else {
			talk.append("\n");
		}
		cout << "\nI Say:(\"quit\"to exit):";
		cout << talk;
		//send(sockClient, talk.c_str(), talk.size(), 0); // 发送信息  
		send(clnSocket, talk.c_str(), 200, 0); // 发送信息  
		ReleaseSemaphore(buffMutex, 1, NULL);     // V（资源占用完毕）   
	}
	return 0;
}


DWORD WINAPI RecvThread(LPVOID IpParameter)
{
	while (1) {
		char recvBuf[300] = { 0 };
		recv(clnSocket, recvBuf, 200, 0);
		WaitForSingleObject(buffMutex, INFINITE);     // P（资源未被占用）    

		cout << "Sever Says:" << recvBuf << endl;

		ReleaseSemaphore(buffMutex, 1, NULL);     // V（资源占用完毕）   
	}
	return 0;
}