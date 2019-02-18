#pragma once
#include <WinSock2.h>
#include <WS2tcpip.h>
#include<iostream>
#include<thread>
#pragma comment(lib, "ws2_32.lib")  //加载 ws2_32.dll

//网络地址
struct STNetAddress
{
	const char* pszIp;
	int iPort;
	int iSocket;
};
/*---------------------------------------------------------------------------
** 类名 : Client
**---------------------------------------------------------------------------
** 功能 : 客户端
**---------------------------------------------------------------------------
** Date			Name
** 2019.02.11	任伟
**---------------------------------------------------------------------------*/
class Client
{
public:

	// 初始化
	Client();

	// 释放
	~Client();

	// 开启网络服务
	bool StartNetService();

	// 网络测试
	bool StartNetServiceTest();

	// 开始广播
	static void SendBroadCast();
private:

	// 连接功能服务器
	int LinkFunctionServer(const char*pszIP, int iPort);
	
	// 等待广播消息
	static void BroadCast(int iServerFd);

	// 获取服务器id
	static int QueryServerSocket();

private:

	static Client* m_pClient; //客户端指针

	std::thread* th_BroadCast; //广播

	int m_iSubServerSocket; // 服务器套接字
};

