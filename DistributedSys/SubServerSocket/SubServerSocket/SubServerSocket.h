#pragma once
#include <WinSock2.h>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")  //加载 ws2_32.dll

#include <iostream>
using namespace std;
/*---------------------------------------------------------------------------
** 类名 : SubServer
**---------------------------------------------------------------------------
** 功能 : 主服务器
**---------------------------------------------------------------------------
** Date			Name
** 2018.02.06	任伟
**---------------------------------------------------------------------------*/
class SubServer
{
public:

	// 初始化
	SubServer();

	// 释放
	~SubServer();
public:

	// 开启网络服务
	bool StartSubServer();
private:

	// 创建套接字
	int CreateSocket();

	// 连接主服务器
	bool ConnectMainServer(int iListenSocket);

	// 心跳子线程
	//void SubHeart();

};