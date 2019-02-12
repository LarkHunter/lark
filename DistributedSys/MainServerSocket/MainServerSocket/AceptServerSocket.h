#pragma once
#include <vector>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>
#pragma comment(lib, "ws2_32.lib")  //加载 ws2_32.dll
typedef std::vector<SOCKET> VecSubServerSocket; // 子服务器套接字

/*---------------------------------------------------------------------------
** 类名 : AceptServerSocket
**---------------------------------------------------------------------------
** 功能 : 处理功能服务器连接
**---------------------------------------------------------------------------
** Date			Name
** 2018.01.31	任伟
**---------------------------------------------------------------------------*/
class AceptServerSocket
{
public:

	// 初始化
	AceptServerSocket();

	// 释放
	~AceptServerSocket();
public:

	// 开启网络服务
	bool StartNetService();

private:

	// 创建套接字
	int CreateSocket();

	// 绑定套接字
	bool BindSocket(int iListenSocket);

	// 监听套接字
	bool ListenSocket(int iListenSocket);

	// 接受客户端请求
	bool AcceptSocket(int iListenSocket);

	// 检测子线程心跳
	static void DetectSubServerHeart();

	// 检测子服务器
	static void DetectSubServer();

	// 检测子服务器网络连接
	static void DetectSubServerConnect(int iAcceptSocket);

	// 分配功能服务器
	static int DistributeServerSocket();

private:
	static AceptServerSocket* m_AceptServerSocket;

	VecSubServerSocket m_vecSubServerSocket; // 子服务器的连接套接字
};

