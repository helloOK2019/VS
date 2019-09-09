#include"Client.h"
#include<iostream>
#include <WS2tcpip.h>
#include <string>  
#include"winsock2.h"
#pragma comment(lib,"ws2_32.lib")
using namespace std;

SOCKET clnSocket;

void endFunc()
{
	cout << "----------end----------" << endl;
	system("pause");
}

Client::Client() {};
Client::~Client() {};
Client::Client(int port, char* ip)
{
	m_port = port;
	m_ip = ip;
}

void Client::createSocket()
{
	//1.初始化套接字
	WSADATA wsd;
	if (WSAStartup(MAKEWORD(2, 2), &wsd) != 0)
	{
		cout << "WSAStartup failed!" << endl;
		return ;
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
		return ;
	}
	else
	{
		cout << "2.socket succeeded!" << endl;
	}

	//绑定套接字
	memset(&m_addrSrv, 0, sizeof(m_addrSrv));
	m_addrSrv.sin_family = AF_INET;
	m_addrSrv.sin_port = htons(m_port);
	inet_pton(AF_INET, m_ip, &m_addrSrv.sin_addr);
	return ;
}


int Client::clientConnect()
{
	//发起连接
	int retVal = connect(clnSocket, (SOCKADDR*)& m_addrSrv, sizeof(SOCKADDR));
	if (SOCKET_ERROR == retVal)
	{
		cout << "connect failed!" << endl;
		return 1;
	}
	else
	{
		cout << "3.connect succeeded!" << endl;
		cout << "quit to exit" << endl;
		return 0;
	}
}

void Client::clientRecv()
{
	char recvBuf[300] = { 0 };	
	recv(clnSocket, recvBuf, 200, 0);//接收消息
	cout << "Sever Says:" << recvBuf << endl;
}

int Client::clientSend(char* pszMess)
{
	if (strcmp(pszMess, "quit") == 0)
	{
		send(clnSocket, pszMess, 200, 0);
		cout << "Class quit part" << endl;
		return 0;
	}
	send(clnSocket, pszMess, 200, 0); // 发送信息  
	return 1;
}

void Client::closeSocket()
{
	closesocket(clnSocket);
	return ;
}