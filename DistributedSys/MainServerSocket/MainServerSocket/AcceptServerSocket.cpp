#include "AceptServerSocket.h"
#include<thread>

#define DEFAULT_BUFLEN 512

AceptServerSocket* AceptServerSocket::m_AceptServerSocket = NULL;

/*--------------------------------------------------------------------
** 名称 : DetectSubServerHeart
**--------------------------------------------------------------------
** 功能 : 检测子服务器心跳
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.02.07		任伟
**-------------------------------------------------------------------*/
void AceptServerSocket::DetectSubServerHeart()
{
	while (1)
	{
		Sleep(5000);
		DetectSubServer();
	}
}

/*--------------------------------------------------------------------
** 名称 : AceptServerSocket
**--------------------------------------------------------------------
** 功能 : 初始化
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.02.06		任伟
**-------------------------------------------------------------------*/
AceptServerSocket::AceptServerSocket()
{
	m_AceptServerSocket = this;
}
/*--------------------------------------------------------------------
** 名称 : ~AceptServerSocket
**--------------------------------------------------------------------
** 功能 : 释放
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.02.06		任伟
**-------------------------------------------------------------------*/
AceptServerSocket::~AceptServerSocket()
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
** 19.02.06		任伟
**-------------------------------------------------------------------*/
bool AceptServerSocket::StartNetService()
{
	// 创建套接字
	int iListenSocket = CreateSocket();

	if(INVALID_SOCKET == iListenSocket)
	{
		return false;
	}

	// 绑定套接字
	bool bResult = BindSocket(iListenSocket);
	if(!bResult)
	{
		return false;
	}

	// 设置监听
	bResult = ListenSocket(iListenSocket);
	if(!bResult)
	{
		return false;
	}

	/*在子线程中处理请求*/
	std::thread t_detectSubServer(DetectSubServerHeart);
	//tSocket.join();
	while(1)
	{
		AcceptSocket(iListenSocket);
		Sleep(5000);
		std::cout << "good Accept"<<std::endl;
	}

	t_detectSubServer.join();
	return true;
}
/*--------------------------------------------------------------------
** 名称 : CreateSocket
**--------------------------------------------------------------------
** 功能 : 创建套接字
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.01.31		任伟
**-------------------------------------------------------------------*/
int AceptServerSocket::CreateSocket()
{
	//初始化DLL
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if(NO_ERROR != iResult)
	{
		return 0;
	}

	//创建套接字
	SOCKET ListenSocket = INVALID_SOCKET;
	ListenSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (INVALID_SOCKET == ListenSocket)
	{
		std::cout << "Create Socket Error!" << std::endl;

		WSACleanup();

		return 0;
	}
	else
	{
		std::cout << "Create Socket Success" << std::endl;
	}
	
	return ListenSocket;
}
/*--------------------------------------------------------------------
** 名称 : BindSocket
**--------------------------------------------------------------------
** 功能 : 绑定套接字
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.01.31		任伟
**-------------------------------------------------------------------*/
bool AceptServerSocket::BindSocket(int iListenSocket)
{
	//----------------------
	// The sockaddr_in structure specifies the address family,
	// IP address, and port for the socket that is being bound.
	// The socket address to be passed to bind
	sockaddr_in service;
	service.sin_family = AF_INET;
	service.sin_addr.s_addr = inet_addr("127.0.0.1");
	service.sin_port = htons(27015);

	//----------------------
	// Bind the socket.
	int iResult = bind(iListenSocket, (SOCKADDR *)&service, sizeof(service));
	if(INVALID_SOCKET == iResult)
	{
		WSACleanup();

		return false;
	}
	else
	{
		std::cout << "Bind Socket Success"<< std::endl;
	}
	return true;

}
/*--------------------------------------------------------------------
** 名称 : ListenSocket
**--------------------------------------------------------------------
** 功能 : 监听套接字
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.01.31		任伟
**-------------------------------------------------------------------*/
bool AceptServerSocket::ListenSocket(int iListenSocket)
{
	if(INVALID_SOCKET == iListenSocket)
	{
		return false;
	}

	int iRet = listen(iListenSocket, SOMAXCONN);
	if(0 != iRet)
	{
		return false;
	}
	else
	{
		std::cout << "Listen Socket Success" << std::endl;
	}
	return true;
}
/*--------------------------------------------------------------------
** 名称 : AcceptSocket
**--------------------------------------------------------------------
** 功能 : 接受客户端请求
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.01.31		任伟
**-------------------------------------------------------------------*/
bool AceptServerSocket::AcceptSocket(int iListenSocket)
{
	if(INVALID_SOCKET == iListenSocket)
	{
		return false;
	}

	SOCKET iAcceptSocket;

	iAcceptSocket = accept(iListenSocket, NULL, NULL);
	if(INVALID_SOCKET != iAcceptSocket)
	{
		m_vecSubServerSocket.push_back(iAcceptSocket);

		int iSocket = DistributeServerSocket();
		std::cout <<"Accept SubServer Socket" << iAcceptSocket << std::endl;
	}

	return true;
}
/*--------------------------------------------------------------------
** 名称 : DetectSubServer
**--------------------------------------------------------------------
** 功能 : 检测子线程心跳
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.02.07		任伟
**-------------------------------------------------------------------*/
void AceptServerSocket::DetectSubServer()
{
	VecSubServerSocket::iterator itSubServer = m_AceptServerSocket->m_vecSubServerSocket.begin();
	if(itSubServer == m_AceptServerSocket->m_vecSubServerSocket.end())
	{
		return;
	}
	for(;itSubServer != m_AceptServerSocket->m_vecSubServerSocket.end();itSubServer++)
	{
		//*itSubServer
		int iSubSocket = *itSubServer;
		DetectSubServerConnect(iSubSocket);
	}
}
/*--------------------------------------------------------------------
** 名称 : DetectSubServerConnect
**--------------------------------------------------------------------
** 功能 : 检测子线程网络连接
**--------------------------------------------------------------------
** 参数 : iAcceptSocket 子线程套接字
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.02.07		任伟
**-------------------------------------------------------------------*/
void AceptServerSocket::DetectSubServerConnect(int iAcceptSocket)
{
	int recvbuflen = DEFAULT_BUFLEN;
	char recvbuf[DEFAULT_BUFLEN] = "";
	int iResult = recv(iAcceptSocket, recvbuf, recvbuflen, 0);
	if(iResult > 0)
	{
		wprintf(L"Bytes received: %d\n", iResult);
		std::cout <<"[AcceptSocket]"<< iAcceptSocket << "Reiceived Value is " << recvbuf << " Length is  " << recvbuflen << std::endl;
	}
	else if(0 == iResult)
	{
		wprintf(L"Connection closed\n");
		closesocket(iAcceptSocket);
	}
	else
	{
		wprintf(L"recv failed with error: %d\n", WSAGetLastError());
		closesocket(iAcceptSocket);
	}
	std::cout << "Accept Success" << std::endl;
}

/*--------------------------------------------------------------------
** 名称 : DistributeServerSocket
**--------------------------------------------------------------------
** 功能 : 分配服务器
**--------------------------------------------------------------------
** 参数 : NULL 
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.02.12		任伟
**-------------------------------------------------------------------*/
int AceptServerSocket::DistributeServerSocket()
{
	int iSize = m_AceptServerSocket->m_vecSubServerSocket.size();
	
	int iCount = rand() % iSize;

	if(iCount <=0 
		||iCount>=iSize)
	{
		return 0;
	}
	int iSocket = m_AceptServerSocket->m_vecSubServerSocket.at(iCount);

	return iSocket;
}
