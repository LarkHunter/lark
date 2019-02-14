#include "SelectClientSocket.h"
#include "AcceptServerSocket.h"

/*--------------------------------------------------------------------
** 名称 : SelectClientSocket
**--------------------------------------------------------------------
** 功能 : 初始化
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.02.12		任伟
**-------------------------------------------------------------------*/
SelectClientSocket::SelectClientSocket()
{

}

/*--------------------------------------------------------------------
** 名称 : ~SelectClientSocket
**--------------------------------------------------------------------
** 功能 : 释放
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.02.12		任伟
**-------------------------------------------------------------------*/
SelectClientSocket::~SelectClientSocket()
{

}
/*--------------------------------------------------------------------
** 名称 : StartNetService
**--------------------------------------------------------------------
** 功能 : 初始化网络服务
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : 套接字
**--------------------------------------------------------------------
** Date:		Name
** 19.02.14		任伟
**-------------------------------------------------------------------*/
bool SelectClientSocket::StartNetService()
{
	// 初始化网络
	int iSeverFd = InitSocket();

	if(iSeverFd <=0)
	{
		return false;
	}

	// 轮询套客户端连接
	bool bResult = SelectCilentConnect(iSeverFd);

	return bResult;

}

/*--------------------------------------------------------------------
** 名称 : InitSocket
**--------------------------------------------------------------------
** 功能 : 初始化网络
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : serverfd
**--------------------------------------------------------------------
** Date:		Name
** 19.02.12		任伟
**-------------------------------------------------------------------*/
int SelectClientSocket::InitSocket()
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

		return 0;
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
	iResult = bind(iListenSocket, (SOCKADDR *)&service, sizeof(service));
	if (INVALID_SOCKET == iResult)
	{
		WSACleanup();

		return 0;
	}
	else
	{
		std::cout << "Bind Socket Success" << std::endl;
	}

	int iRet = listen(iListenSocket, SOMAXCONN);
	if (0 != iRet)
	{
		return 0;
	}
	else
	{
		std::cout << "Listen Socket Success" << std::endl;
	}

	return iListenSocket;
}
/*--------------------------------------------------------------------
** 名称 : SelectCilentConnect
**--------------------------------------------------------------------
** 功能 : 轮询客户端连接
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : serverfd
**--------------------------------------------------------------------
** Date:		Name
** 19.02.14		任伟
**-------------------------------------------------------------------*/
bool SelectClientSocket::SelectCilentConnect(int iSeverSocketfd)
{
	if (0 == iSeverSocketfd)
	{
		return false;
	}

	fd_set client_fdset;	/*监控文件描述符集合*/
	struct timeval tv;		/*超时返回时间*/

	tv.tv_sec = 5;
	tv.tv_usec = 0;
	while (1)
	{
		/*初始化文件描述符号到集合*/
		FD_ZERO(&client_fdset);

		/*加入服务器描述符*/
		FD_SET(iSeverSocketfd, &client_fdset);

		int ret = select(iSeverSocketfd + 1, &client_fdset, NULL, NULL, &tv);
		if(ret < 0) // 出错 -1
		{
			perror("select error!\n");

			Sleep(5000);
			continue;

			//break;
		}
		else if (ret == 0) // 超时 0
		{
			printf("timeout!\n");

			continue;
		}

		if(FD_ISSET(iSeverSocketfd, &client_fdset))
		{
			struct sockaddr_in client_addr;
			size_t size = sizeof(struct sockaddr_in);

			int sock_client = accept(iSeverSocketfd, NULL, NULL);
			if(sock_client < 0)
			{
				perror("accept error!\n");
				continue;
			}
			else
			{
				std::cout << "sock_client " << sock_client << "Accept" << std::endl;

				m_vecClientFd.push_back(sock_client);

				// 为客户端分配子服务器 
				int iSubServerSocket = AllocateSubServer(); 
				send(sock_client, (char*)&iSubServerSocket, sizeof(iSubServerSocket), 0);

			}

		}

	}
	return true;
}
/*--------------------------------------------------------------------
** 名称 : AllocateSubServer
**--------------------------------------------------------------------
** 功能 : 分配子服务器
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.02.14		任伟
**-------------------------------------------------------------------*/
int SelectClientSocket::AllocateSubServer()
{
	VecSubServerSocket vecSubServerSocket;

	AcceptServerSocket::QueryOnlineSubServer(vecSubServerSocket);

	int iSize = static_cast<int>(vecSubServerSocket.size());

	int iCount = rand() % iSize;

	if(iCount <= 0
		|| iCount >= iSize)
	{
		return 0;
	}

	int iSocket = vecSubServerSocket.at(iCount);

	return iSocket;
}
