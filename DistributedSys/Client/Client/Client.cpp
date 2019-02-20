#include "Client.h"
#define DEFAULT_BUFLEN 256
#define D_BROADCAST_SEND 64

Client* Client::m_pClient = NULL;
/*--------------------------------------------------------------------
** 名称 : Client
**--------------------------------------------------------------------
** 功能 : 初始化
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.02.11		任伟
**-------------------------------------------------------------------*/
Client::Client()
{
	m_pClient = this;
}

/*--------------------------------------------------------------------
** 名称 : ~Client
**--------------------------------------------------------------------
** 功能 : 释放
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.02.11		任伟
**-------------------------------------------------------------------*/
Client::~Client()
{
	delete th_BroadCast;
}

/*--------------------------------------------------------------------
** 名称 : StartNetService
**--------------------------------------------------------------------
** 功能 : 开启网络服务
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.02.11		任伟
**-------------------------------------------------------------------*/
bool Client::StartNetService()
{
	//初始化DLL
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (NO_ERROR != iResult)
	{
		return 0;
	}

	//创建套接字
	SOCKET iListenSocket = INVALID_SOCKET;
	iListenSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	if(INVALID_SOCKET == iListenSocket)
	{
		std::cout << "Create Socket Error!" << std::endl;

		WSACleanup();

		return false;
	}
	else
	{
		std::cout << "Create Socket Success" << std::endl;
	}

	sockaddr_in service;

	service.sin_family = AF_INET;
	service.sin_addr.s_addr = inet_addr("127.0.0.1");
	service.sin_port = htons(6666);

	//----------------------
	// Bind the socket.
	iResult = connect(iListenSocket, (SOCKADDR *)&service, sizeof(service));
	if (0 != iResult)
	{
		std::cout << "ConnectMainServer Failed " << iResult << std::endl;
	}
	else
	{
		std::cout << "ConnectMainServer Success!" << std::endl;
		//const char *buf = "OK";
		//send(iListenSocket, buf, strlen(buf), 0);
		char recvbuf[DEFAULT_BUFLEN];
		int recvbuflen = DEFAULT_BUFLEN;

		iResult = recv(iListenSocket, recvbuf, recvbuflen, 0);
		if(iResult > 0)
		{
			std::cout << "  recvbuf= " << recvbuf << std::endl;
			printf("recvbuf = %s\n", recvbuf);

			m_iSubServerSocket = LinkFunctionServer("127.0.0.1",9999);

			if(m_iSubServerSocket > 0)
			{
				th_BroadCast = new std::thread(BroadCast,static_cast<int>(m_iSubServerSocket)); //收听广播

			}
		}
		else if(0 == iResult)
		{
			std::cout <<"Connection Closed!" << std::endl;
		}
		else
		{
			std::cout << "Received Error"<< WSAGetLastError()<< std::endl;
		}
	}

	return true;
}
/*--------------------------------------------------------------------
** 名称 : StartNetServiceTest
**--------------------------------------------------------------------
** 功能 : 网络测试
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.02.18		任伟
**-------------------------------------------------------------------*/
bool Client::StartNetServiceTest()
{
	m_iSubServerSocket = LinkFunctionServer("127.0.0.1", 9999);

	if(m_iSubServerSocket > 0)
	{
		th_BroadCast = new std::thread(BroadCast, static_cast<int>(m_iSubServerSocket)); //收听广播

	}
	return true;
}

/*--------------------------------------------------------------------
** 名称 : SendBroadCast
**--------------------------------------------------------------------
** 功能 : 开始广播
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.02.18		任伟
**-------------------------------------------------------------------*/
void Client::SendBroadCast()
{
	char chSend[D_BROADCAST_SEND];

	while(true)
	{
		memset(chSend, 0, strlen(chSend));

		gets_s(chSend);
		int iServerSocket = QueryServerSocket();

		send(iServerSocket, chSend, sizeof(chSend), 0);
	}
	
}

/*--------------------------------------------------------------------
** 名称 : LinkFunctionServer
**--------------------------------------------------------------------
** 功能 : 连接功能服务器
**--------------------------------------------------------------------
** 参数 : pszIP IP
** 参数 : iPort 端口
** 参数 : iSocket 套接字
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.02.15		任伟
**-------------------------------------------------------------------*/
int Client::LinkFunctionServer(const char* pszIP, int iPort)
{
	if(iPort <= 0)
	{
		return 0;
	}

	//初始化DLL
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if(NO_ERROR != iResult)
	{
		return 0;
	}

	//创建套接字
	SOCKET iListenSocket = INVALID_SOCKET;
	iListenSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	if(INVALID_SOCKET == iListenSocket)
	{
		std::cout << "Create Socket Error!" << std::endl;

		WSACleanup();

		return 0;
	}
	else
	{
		std::cout << "Create Socket Success" << std::endl;
	}

	sockaddr_in service;

	service.sin_family = AF_INET;
	service.sin_addr.s_addr = inet_addr(pszIP);
	service.sin_port = htons(iPort);

	//----------------------
	// Bind the socket.
	iResult = connect(iListenSocket, (SOCKADDR *)&service, sizeof(service));
	if(0 != iResult)
	{
		std::cout << "ConnectFunctionServer Failed " << iResult << std::endl;

		return 0;
	}
	else
	{
		std::cout << "ConnectFunctionServer Success " << iResult << std::endl;

		char buffer[256];
		//strcmp(buffer, "OK I Came");
		sprintf(buffer, "OK I Came");
		send(iListenSocket, buffer, strlen(buffer), 0);
	}

	return iListenSocket;
}
/*--------------------------------------------------------------------
** 名称 : BroadCast
**--------------------------------------------------------------------
** 功能 : 广播
**--------------------------------------------------------------------
** 参数 : iServerFd 服务器套接字
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.02.15		任伟
**-------------------------------------------------------------------*/
void Client::BroadCast(int iServerFd)
{
	while(1)
	{
		char recvbuf[DEFAULT_BUFLEN];
		int recvbuflen = DEFAULT_BUFLEN;

		int iResult = recv(iServerFd, recvbuf, recvbuflen, 0);
		if(iResult > 0)
		{
			std::cout << "Reveived BroadCast "<< recvbuf << std::endl;
		}
		else if (0 == iResult)
		{
			std::cout << "Connection Closed!" << std::endl;
		}
// 		else
// 		{
// 			std::cout << "Received Error" << WSAGetLastError() << std::endl;
// 		}

		//Sleep(5000);
	}
}
/*--------------------------------------------------------------------
** 名称 : QueryServerSocket
**--------------------------------------------------------------------
** 功能 : 获取服务器套接字
**--------------------------------------------------------------------
** 参数 : NULL 
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.02.18		任伟
**-------------------------------------------------------------------*/
int Client::QueryServerSocket()
{
	int iServerSocket = m_pClient->m_iSubServerSocket;

	return iServerSocket;
}

