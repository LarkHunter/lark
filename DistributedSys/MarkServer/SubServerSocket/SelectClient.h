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

	// 响应客户端连接
	static bool th_DealClientConnect(int iServerfd);

	// 处理广播
	static void DealBroadCast(char*  bufferSend);

	// 获取新增客户端套接字
	static int QuerySockClient();

	// 设置新增客户端套接字
	static void SetSocketClient(int iSock_client);
private:

	static SelectClient * m_pSelectClient; // 轮询客户端连接模块

	VecClientFd m_VecClientFd; // 已经连接上的客户端套接字描述符

	std::thread *m_thSelectClient; // 轮询客户端请求线程

	int m_iSock_client;// 客户端连接

};

