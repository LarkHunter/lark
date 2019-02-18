#include "SelectClient.h"

SelectClient * SelectClient::m_pSelectClient = NULL;
/*--------------------------------------------------------------------
** 名称 : SelectClient
**--------------------------------------------------------------------
** 功能 : 初始化
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.02.10		任伟
**-------------------------------------------------------------------*/
SelectClient::SelectClient()
{
	m_pSelectClient = this;
}

/*--------------------------------------------------------------------
** 名称 : ~SubServer
**--------------------------------------------------------------------
** 功能 : 释放
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.02.10		任伟
**-------------------------------------------------------------------*/
SelectClient::~SelectClient()
{
	delete m_thSelectClient;

}

/*--------------------------------------------------------------------
** 名称 : InitNetService
**--------------------------------------------------------------------
** 功能 : 初始化网络服务
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.02.10		任伟
**-------------------------------------------------------------------*/
bool SelectClient::InitNetService()
{
	int iServerfd = InitSocket();

	m_thSelectClient = new std::thread(th_DealClientConnect,iServerfd); // 处理客户端连接

	return true;
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
** 19.02.10		任伟
**-------------------------------------------------------------------*/
int SelectClient::InitSocket()
{
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
	service.sin_addr.s_addr = inet_addr("127.0.0.1");
	service.sin_port = htons(9999);

	//----------------------
	// Bind the socket.
	iResult = bind(iListenSocket, (SOCKADDR *)&service, sizeof(service));
	if(INVALID_SOCKET == iResult)
	{
		WSACleanup();

		return 0;
	}
	else
	{
		std::cout << "Bind Socket Success" << std::endl;
	}

	int iRet = listen(iListenSocket, SOMAXCONN);
	if(0 != iRet)
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
** 名称 : th_DealClientConnect
**--------------------------------------------------------------------
** 功能 : 处理网络请求
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : serverfd
**--------------------------------------------------------------------
** Date:		Name
** 19.02.10		任伟
**-------------------------------------------------------------------*/
bool SelectClient::th_DealClientConnect(int iServerfd)
{
	if(0 == iServerfd)
	{
		return false;
	}

	fd_set client_fdset;	/*监控文件描述符集合*/
	struct timeval tv;		/*超时返回时间*/

	tv.tv_sec = 5;
	tv.tv_usec = 0;
	while(1)
	{
		/*初始化文件描述符号到集合*/
		FD_ZERO(&client_fdset);

		/*加入服务器描述符*/
		FD_SET(iServerfd, &client_fdset);

		int ret = select(iServerfd + 1, &client_fdset, NULL, NULL, &tv);
		if(ret < 0) // 出错 -1
		{
			perror("select error!\n");
			
			Sleep(5000);
			continue;
			
			//break;
		}
		else if(ret == 0) // 超时 0
		{
			printf("timeout!\n");
	
			continue;
		}

		if(FD_ISSET(iServerfd, &client_fdset))
		{
			struct sockaddr_in client_addr;
			size_t size = sizeof(struct sockaddr_in);

			int sock_client = accept(iServerfd, NULL, NULL);
			if(sock_client < 0)
			{
				perror("accept error!\n");
				continue;
			}
			else
			{
				std::cout << "sock_client "<< sock_client <<"Accept"<< std::endl;
				
				m_pSelectClient->m_VecClientFd.push_back(sock_client);

				// 广播
				DealBroadCast(sock_client);

				//int iSend = 666;
			//	send(sock_client, (char*)&iSend, sizeof(iSend), 0);

			}

		}

	}
	return true;
}
/*--------------------------------------------------------------------
** 名称 : DealBroadCast
**--------------------------------------------------------------------
** 功能 : 处理广播
**--------------------------------------------------------------------
** 参数 : sock_client 客户端连接
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.02.10		任伟
**-------------------------------------------------------------------*/
void SelectClient::DealBroadCast(int sock_client)
{
	char buffer[1024];
	memset(buffer, 0, sizeof(buffer));
	
	int ret = recv(sock_client, buffer, 1024, 0);
	if(ret < 0)
	{
		perror("recv error!\n");
				
		WSACleanup();
		return;
	}

	VecClientFd::iterator itClientFd = m_pSelectClient->m_VecClientFd.begin();
	for(itClientFd;itClientFd!= m_pSelectClient->m_VecClientFd.end();itClientFd++)
	{
		int iClientFd = *itClientFd;
		send(iClientFd, buffer,sizeof(buffer),0);
	}
}
