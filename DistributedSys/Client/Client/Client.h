#pragma once
#include <WinSock2.h>
#include <WS2tcpip.h>
#include<iostream>

#pragma comment(lib, "ws2_32.lib")  //���� ws2_32.dll

/*---------------------------------------------------------------------------
** ���� : Client
**---------------------------------------------------------------------------
** ���� : �ͻ���
**---------------------------------------------------------------------------
** Date			Name
** 2019.02.11	��ΰ
**---------------------------------------------------------------------------*/
class Client
{
public:

	// ��ʼ��
	Client();

	// �ͷ�
	~Client();

	// �����������
	bool StartNetService();
};
