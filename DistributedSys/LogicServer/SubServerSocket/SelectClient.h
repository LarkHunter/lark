#pragma once
#include <winsock2.h>
#include <iostream>
#include <vector>
#include <thread>
#pragma comment(lib, "ws2_32.lib")  //加载 ws2_32.dll

typedef std::vector<int> VecClientFd; // 保存已经连接上的客户端套接字描述符

/*---------------------------------------------------------------------------
** 类名 : SubServer
**---------------------------------------------------------------------------
** 功能 : 子服务器
**---------------------------------------------------------------------------
** Date			Name
** 2018.02.06	任伟
**---------------------------------------------------------------------------*/
class SelectClient
{
public:

	// 初始化
	SelectClient();

	// 释放
	~SelectClient();

	// 初始化网络服务
	bool InitNetService();

private:

	// 初始化套接字
	int InitSocket();

	// 处理客户端请求
	bool DealNetRequest(int iServerfd);

private:

	VecClientFd m_VecClientFd; // 已经连接上的客户端套接字描述符

};

