#pragma once
#include <vector>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>
#pragma comment(lib, "ws2_32.lib")  //���� ws2_32.dll
typedef std::vector<SOCKET> VecSubServerSocket; // �ӷ������׽���
/*---------------------------------------------------------------------------
** ���� : MainServer
**---------------------------------------------------------------------------
** ���� : ��������
**---------------------------------------------------------------------------
** Date			Name
** 2018.01.31	��ΰ
**---------------------------------------------------------------------------*/
class MainServer
{
public:

	// ��ʼ��
	MainServer();

	// �ͷ�
	~MainServer();
public:

	// �����������
	bool StartNetService();

private:

	// �����׽���
	int CreateSocket();

	// ���׽���
	bool BindSocket(int iListenSocket);

	// �����׽���
	bool ListenSocket(int iListenSocket);

	// ���ܿͻ�������
	bool AcceptSocket(int iListenSocket);

	// ������߳�����
	static void DetectSubServerHeart();

	// ����ӷ�����
	static void DetectSubServer();

	// ����ӷ�������������
	static void DetectSubServerConnect(int iAcceptSocket);

private:
	static MainServer* m_MainServer;

	VecSubServerSocket m_vecSubServerSocket; // �ӷ������������׽���
};
