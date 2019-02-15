#include "Client.h"
#define DEFAULT_BUFLEN 512


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
	service.sin_port = htons(27015);

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
			std::cout << "  = " << recvbuf << std::endl;
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
** 名称 : ConnectFunctionServer
**--------------------------------------------------------------------
** 功能 : 连接功能服务器
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.02.15		任伟
**-------------------------------------------------------------------*/
bool Client::LinkFunctionServer()
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

	if (INVALID_SOCKET == iListenSocket)
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
	service.sin_port = htons(27015);

	//----------------------
	// Bind the socket.
	iResult = connect(iListenSocket, (SOCKADDR *)&service, sizeof(service));
	if(0 != iResult)
	{
		std::cout << "ConnectMainServer Failed " << iResult << std::endl;
	}
	else
	{
		std::cout << "ConnectMainServer Success " << iResult << std::endl;
	}
}
