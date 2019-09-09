#ifndef _Client_H_
#define _Client_H_
#include <WS2tcpip.h>
void endFunc();

class Client
{
public:
	Client();
	Client(int port, char* ip);
	~Client();
	void createSocket();
	int clientConnect();
	void clientRecv();
	int clientSend(char* pszMess);
	void closeSocket();
private:
	int m_port;
	char* m_ip;
	struct sockaddr_in m_addrSrv;
};

#endif