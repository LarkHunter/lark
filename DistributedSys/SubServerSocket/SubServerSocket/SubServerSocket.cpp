#include "SubServerSocket.h"
#include <thread>
#include <windows.h>

/*--------------------------------------------------------------------
** 名称 : SubHeart
**--------------------------------------------------------------------
** 功能 : 子线程心跳，定时发送心跳包
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.02.06		任伟
**-------------------------------------------------------------------*/
void SubHeart(int iListenSocket)
{
	const char *buf = "Alived";
	while(1)
	{
		cout <<"buf = " << buf << "sizeof(buf)!"<< strlen(buf) <<endl;
		send(iListenSocket,buf, strlen(buf),0);

		Sleep(5000);
	}
}

/*--------------------------------------------------------------------
** 名称 : SubServer
**--------------------------------------------------------------------
** 功能 : 初始化
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.02.06		任伟
**-------------------------------------------------------------------*/
SubServer::SubServer()
{

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
** 19.02.06		任伟
**-------------------------------------------------------------------*/
SubServer::~SubServer()
{

}
/*--------------------------------------------------------------------
** 名称 : StartSubServer
**--------------------------------------------------------------------
** 功能 : 开启网络服务
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.02.06		任伟
**-------------------------------------------------------------------*/
bool SubServer::StartSubServer()
{ 
	int iSocket = CreateSocket();
	if(0 == iSocket)
	{
		std::cout <<"CreateSocket Falied " <<std::endl;

		return false;
	}

	bool bResult = ConnectMainServer(iSocket);
	
	return bResult;

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
** 19.02.06		任伟
**-------------------------------------------------------------------*/
int SubServer::CreateSocket()
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

	if(INVALID_SOCKET == ListenSocket)
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
** 名称 : ConnectMainServer
**--------------------------------------------------------------------
** 功能 : 连接主服务器
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.02.06		任伟
**-------------------------------------------------------------------*/
bool SubServer::ConnectMainServer(int iListenSocket)
{
	sockaddr_in service;

	service.sin_family = AF_INET;
	service.sin_addr.s_addr = inet_addr("127.0.0.1");
	service.sin_port = htons(27015);

	//----------------------
	// Bind the socket.
	int iResult = connect(iListenSocket, (SOCKADDR *)&service, sizeof(service));
	if(0 != iResult)
	{
		std::cout <<"ConnectMainServer Failed " << iResult << std::endl;
	}
	else
	{
		std::cout << "ConnectMainServer Success!" << std::endl;

		// 开启心跳
		std::thread th_Heart(SubHeart, iListenSocket);

		//std::cout << "...." << std::endl;
		th_Heart.join();
	}



	return true;
}


