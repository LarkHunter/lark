#pragma once
#include <winsock2.h>
#include <iostream>

#pragma comment(lib, "ws2_32.lib")  //���� ws2_32.dll

/*---------------------------------------------------------------------------
** ���� : SubServer
**---------------------------------------------------------------------------
** ���� : �ӷ�����
**---------------------------------------------------------------------------
** Date			Name
** 2018.02.06	��ΰ
**---------------------------------------------------------------------------*/
class SubServer
{
public:

	// ��ʼ��
	SubServer();

	// �ͷ�
	~SubServer();

	// ��ʼ���������
	bool InitNetService();

	// ��ʼ���׽���
	int InitSocket();

	// �����ͻ�������
	bool DealNetRequest(int iServerfd);

};
