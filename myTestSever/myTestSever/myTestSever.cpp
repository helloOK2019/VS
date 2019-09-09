/////////////////////////////////////////////////////////////
//Author:hello_OK
//Created:2019/07/17
//Describe:简易服务器
/////////////////////////////////////////////////////////////
#include <iostream>
#include"winsock2.h"
#pragma comment(lib,"ws2_32.lib")
using namespace std;

int main()
{
	//1.初始化DLL
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

	//2.创建套接字
	SOCKET mySocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == mySocket)
	{
		cout << "socket() failed!" << endl;
		return 1;
	}
	else
	{
		cout << "2.socket succeeded!" << endl;
	}

	//3.绑定套接字
	sockaddr_in sockAddr;
	memset(&sockAddr, 0, sizeof(sockAddr));
	sockAddr.sin_family = AF_INET;		//地址族
	sockAddr.sin_port = htons(4999);	//端口号
	sockAddr.sin_addr.s_addr = INADDR_ANY;
	int retVal = bind(mySocket, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
	if (SOCKET_ERROR == retVal)
	{
		cout << "bind() failed!" << endl;
		closesocket(mySocket);
		WSACleanup();
		return 1;
	}
	else
	{
		cout << "3.bind succeeded!" << endl;
	}

	//4.监听
	retVal = listen(mySocket, 10);
	if (SOCKET_ERROR == retVal)
	{
		cout << "listen failed!" << endl;
		closesocket(mySocket);
		WSACleanup();
		return 1;
	}
	else
	{
		cout << "4.listen succeeded!" << endl;
	}

	//5.接受请求
	SOCKADDR clnAddr;
	int nclnAddr = sizeof(SOCKADDR);
	SOCKET clnSock = accept(mySocket, (SOCKADDR*)& clnAddr, &nclnAddr);
	if (SOCKET_ERROR == clnSock)
	{
		cout << "accept() failed!" << endl;
		closesocket(mySocket);
		WSACleanup();
		return 1;
	}
	else
	{
		cout << "5.accept succeeded!" << endl;
	}

	//发送数据
	const char *str = "hello_OK";
	send(clnSock, str, strlen(str) + sizeof(char), NULL);
	
	//接收数据
	char recBuff[200];
	memset(recBuff, 0, sizeof(recBuff));
	recv(clnSock, recBuff, 200, 0);
	cout << recBuff << endl;

	//关闭套接字
	closesocket(clnSock);
	closesocket(mySocket);

}