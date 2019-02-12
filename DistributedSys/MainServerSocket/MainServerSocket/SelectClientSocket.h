#pragma once
#include <winsock2.h>
#include <iostream>
#include <vector>
#pragma comment(lib, "ws2_32.lib")  //加载 ws2_32.dll

/*---------------------------------------------------------------------------
** 类名 : SelectClientSocket
**---------------------------------------------------------------------------
** 功能 : 登录服务器轮询客户端连接
**---------------------------------------------------------------------------
** Date			Name
** 2019.02.12	任伟
**---------------------------------------------------------------------------*/
class SelectClientSocket
{
public:
	
	// 初始化
	SelectClientSocket();

	// 释放
	~SelectClientSocket();
public:

	// 初始化网络服务
	bool InitNetService();

private:

	// 初始化套接字
	int InitSocket();

	
};

