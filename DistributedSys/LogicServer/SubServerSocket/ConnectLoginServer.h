#pragma once
#include <thread>
#include <WinSock2.h>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")  //加载 ws2_32.dll

#include <iostream>
using namespace std;
/*---------------------------------------------------------------------------
** 类名 : ConnectLoginServer
**---------------------------------------------------------------------------
** 功能 : 主服务器
**---------------------------------------------------------------------------
** Date			Name
** 2018.02.06	任伟
**---------------------------------------------------------------------------*/
class ConnectLoginServer
{
public:

	// 初始化
	ConnectLoginServer();

	// 释放
	~ConnectLoginServer();
public:

	// 开启网络服务
	bool StartNetService();
private:

	// 创建套接字
	int CreateSocket();

	// 连接主服务器
	bool ConnectMainServer(int iListenSocket);

	// 心跳子线程
	//void SubHeart();
private:
	std::thread *th_heartToLoginServer;
};