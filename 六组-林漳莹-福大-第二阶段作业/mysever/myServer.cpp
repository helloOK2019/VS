// OneServerMain.cpp  
#include "pch.h"
#include <iostream>  
#include <cstdio>  
#include <string>  
#include <vector>  
#include <iterator>  
#include <algorithm>  

#include"winsock2.h"
#pragma comment(lib,"ws2_32.lib")
using namespace std;
HANDLE bufferMutex;     // 令其能互斥成功正常通信的信号量句柄  
//SOCKET sClient;        // 客户端的套接字  
vector <SOCKET> clientSocketGroup;

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
	SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == serverSocket)
	{
		cout << "socket failed!" << endl;
		WSACleanup();
		return -1;
	}
	cout << "********************欢迎使用网龙实训平台服务器********************\n";
	//struct sockaddr{ u_sort sa_family;char sa_data[14];}; family指定该地址家族 data起到占位占用一块内存分配区的作用
	//在TCP/IP中用sockaddr_in结构代替sockaddr，从而方便填写地址
	//struct sockaddr_in{shot sin_family; unsigned short sin_port; struct in_addr sin_addr; char sin_zero[8]	
	SOCKADDR_IN servAddr;//服务器地址
	servAddr.sin_family = AF_INET;			//sin_family表示地址族，对于IP地址，sin_family就是AF_INET
	servAddr.sin_port = htons(4999);		//sin_port指定将要分配给套接字的端口
	servAddr.sin_addr.s_addr = INADDR_ANY;	//sin_addr指定套接字主机的IP地址	将IP地址指定为INADDR_ANY,则允许套接字向任何分配给本地机器的IP地址发送和接收数据
											//如果只想使用套接字多个IP地址中的一个，可用inet_addr()指定实际地址
	//绑定套接字
	//int bind(SOCKET s, const struct sockaddr* name, int namelen);
	//三个参数分别指定需要绑定的套接字、该套接字的本地地址信息，该地址结构会随所用的网络协议的不同而不同、指定该网络协议地址的长度
	int retVal = ::bind(serverSocket, (LPSOCKADDR)&servAddr, sizeof(SOCKADDR_IN));//类型强制转换,LPSOCKADDR为结构指针 ;typedef struct sockaddr *PSOCKADDR;==>(LPSOCKADDR)相当于(SOCKADDR*)
	if (SOCKET_ERROR == retVal)
	{
		cout << "bind failed!\n";
		closesocket(serverSocket);
		WSACleanup();
		return -1;
	}
	//开始监听
	//将套接字设置为监听模式（连接请求），listen（）通知TCP服务器准备接收
	//int listen(SOCKET s, int backlog);
	//第一个参数制定需要设置的套接字，第二个参数为（等待连接队列的最大长度）
	retVal = listen(serverSocket, 10);
	if (SOCKET_ERROR == retVal)
	{
		cout << "listen failed!\n";
		closesocket(serverSocket);
		WSACleanup();
		return -1;
	}
	cout << "欢迎使用网龙实训平台服务器\n输入quit退出\n";
	// accept()，接收连接，等待客户端连接  

	bufferMutex = CreateSemaphore(NULL, 1, 1, NULL);

	DWORD WINAPI SendMessageThread(LPVOID IpParameter);
	DWORD WINAPI ReceiveMessageThread(LPVOID IpParameter);

	HANDLE sendThread = CreateThread(NULL, 0, SendMessageThread, NULL, 0, NULL);

	while (true)
	{    // 不断等待客户端请求的到来  
		//接受客户请求
		sockaddr_in addrClient;
		int addrClientlen = sizeof(addrClient);
		SOCKET sClient = accept(serverSocket, (sockaddr* FAR)&sClient, &addrClientlen); //客户端的套接字
		if (SOCKET_ERROR != sClient)
		{
			clientSocketGroup.push_back(sClient);
		}
		else
		{
			cout << "accept failed!\n";
			closesocket(serverSocket);
			WSACleanup();
			return -1;
		}
		HANDLE receiveThread = CreateThread(NULL, 0, ReceiveMessageThread, (LPVOID)sClient, 0, NULL);
		WaitForSingleObject(bufferMutex, INFINITE);     // P（资源未被占用）   
		if (NULL == receiveThread) {
			printf("\nCreatThread AnswerThread() failed.\n");
		}
		else
		{
			printf("\nCreate Receive Client Thread OK.\n");
		}
		ReleaseSemaphore(bufferMutex, 1, NULL);     // V（资源占用完毕）  
	}

	WaitForSingleObject(sendThread, INFINITE);  // 等待线程结束  
	CloseHandle(sendThread);
	CloseHandle(bufferMutex);
	WSACleanup();   // 终止对套接字库的使用  
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
	  if("quit" == talk){
			ReleaseSemaphore(bufferMutex, 1, NULL);     // V（资源占用完毕）
			return 0;
		}
		else
		{
			talk.append("\n");
		}
		printf("I Say:(\"quit\"to exit):");
		cout << talk;
		for (int i = 0; i < (int)(clientSocketGroup.size()); ++i) {
			//      send(clientSocketGroup[i], talk.c_str(), talk.size(), 0);   // 发送信息  
			send(clientSocketGroup[i], talk.c_str(), 200, 0);   // 发送信息  
		}
		ReleaseSemaphore(bufferMutex, 1, NULL);     // V（资源占用完毕）   
	}
	return 0;
}


DWORD WINAPI ReceiveMessageThread(LPVOID IpParameter)
{
	SOCKET ClientSocket = (SOCKET)(LPVOID)IpParameter;
	while (1) {
		char recvBuf[300];
		recv(ClientSocket, recvBuf, 200, 0);
		WaitForSingleObject(bufferMutex, INFINITE);     // P（资源未被占用）    

		if (recvBuf[0] == 'q' && recvBuf[1] == 'u' && recvBuf[2] == 'i' && recvBuf[3] == 't' && recvBuf[4] == '\0') {
			vector<SOCKET>::iterator result = find(clientSocketGroup.begin(), clientSocketGroup.end(), ClientSocket);
			clientSocketGroup.erase(result);
			closesocket(ClientSocket);
			ReleaseSemaphore(bufferMutex, 1, NULL);     // V（资源占用完毕）   
			printf("\nAttention: A Client has leave...\n");
			break;
		}

		printf("%s Says: %s\n", "One Client", recvBuf);     // 接收信息  

		ReleaseSemaphore(bufferMutex, 1, NULL);     // V（资源占用完毕）   
	}
	return 0;
}