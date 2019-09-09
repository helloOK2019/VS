#include "pch.h"
#include <iostream>  
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <cstdio>  
#include <string>  
#include"winsock2.h"
#pragma comment(lib,"ws2_32.lib")

using namespace std;

SOCKET sHost;      // 连接成功后的套接字  
HANDLE bufferMutex;     // 令其能互斥成功正常通信的信号量句柄  

int main()
{
	WSADATA wsd;//WSADATA变量
	//初始化套接字动态库，请求2.2版本的Win'Sock库
	if (WSAStartup(MAKEWORD(2, 2), &wsd) != 0)	//WSAStartup是连接应用程序与winsock.dll的第一个调用.其中,第一个参数是WINSOCK 版本号,第二个参数是指向WSADATA的指针.
	{											//该函数返回一个INT型值, 通过检查这个值来确定初始化是否成功.调用格式如下:WSAStartup(MAKEWORD(2, 2), &wsaData), 
		cout << "WSAStartup failed!" << endl;	//其中MAKEWORD(2, 2)表示使用WINSOCK2版本.wsa用来存储系统传回的关于WINSOCK的资料.
		return 1;
	}
	//创建客服端套接字，建立流式套接字，返回套接字号sHost
		//SOCKET socket(int af,int type,int protocol);
		//第一个参数指定地址簇（TCP/TP为AF_INET,PF_INET)	//有两种类型的套接字：基于文件的和面向网络的。家族名：AF_UNIX/AF_INET
		//第二个参数选择套接字类型							//面向连接的套接字SOCK_STREAM与无连接的套接字SOCK_DGRAM
		//第三个参数特定地址家族相关协议(0为自动，IPPROTO_TCP为TCP)
	sHost = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == sHost)
	{
		cout << "socket failed!" << endl;
		WSACleanup();
		return -1;
	}

	// 将套接字sockClient与远程主机相连  
		// int connect( SOCKET s,  const struct sockaddr* name,  int namelen);  
		// 第一个参数：需要进行连接操作的套接字  
		// 第二个参数：设定所需要连接的地址信息  
		// 第三个参数：地址的长度  
	SOCKADDR_IN addrSrv;//服务器地址
	addrSrv.sin_family = AF_INET;			//sin_family表示地址族，对于IP地址，sin_family就是AF_INET
	addrSrv.sin_port = htons((short)4999);		//sin_port指定将要分配给套接字的端口
	addrSrv.sin_addr.s_addr = inet_addr("127.0.0.1");	//sin_addr指定套接字主机的IP地址	将IP地址指定为INADDR_ANY,则允许套接字向任何分配给本地机器的IP地址发送和接收数据

	connect(sHost, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));
	cout << "欢迎使用网龙实训平台客服端\n";

	send(sHost, "\nAttention: A Client has enter...\n", 200, 0);

	bufferMutex = CreateSemaphore(NULL, 1, 1, NULL);

	//声明两个线程
	DWORD WINAPI SendMessageThread(LPVOID IpParameter);
	DWORD WINAPI ReceiveMessageThread(LPVOID IpParameter);

	HANDLE sendThread = CreateThread(NULL, 0, SendMessageThread, NULL, 0, NULL);
	HANDLE receiveThread = CreateThread(NULL, 0, ReceiveMessageThread, NULL, 0, NULL);


	WaitForSingleObject(sendThread, INFINITE);  // 等待线程结束  
	closesocket(sHost);
	CloseHandle(sendThread);
	CloseHandle(receiveThread);
	CloseHandle(bufferMutex);
	WSACleanup();   // 终止对套接字库的使用  

	printf("End linking...\n");
	printf("\n");
	system("pause");
	return 0;
}


DWORD WINAPI SendMessageThread(LPVOID IpParameter)
{
	while (1) {
		string talk;
		getline(cin, talk);
		WaitForSingleObject(bufferMutex, INFINITE);     // P（资源未被占用）    
		if ("quit" == talk) {
			talk.push_back('\0');
			//send(sockClient, talk.c_str(), talk.size(), 0);  
			send(sHost, talk.c_str(), 200, 0);
			break;
		}
		else {
			talk.append("\n");
		}
		printf("\nI Say:(\"quit\"to exit):");
		cout << talk;
		//send(sockClient, talk.c_str(), talk.size(), 0); // 发送信息  
		send(sHost, talk.c_str(), 200, 0); // 发送信息  
		ReleaseSemaphore(bufferMutex, 1, NULL);     // V（资源占用完毕）   
	}
	return 0;
}


DWORD WINAPI ReceiveMessageThread(LPVOID IpParameter)
{
	while (1) {
		char recvBuf[300];
		recv(sHost, recvBuf, 200, 0);
		WaitForSingleObject(bufferMutex, INFINITE);     // P（资源未被占用）    

		printf("%s Says: %s\n", "Server", recvBuf);     // 接收信息  

		ReleaseSemaphore(bufferMutex, 1, NULL);     // V（资源占用完毕）   
	}
	return 0;
}