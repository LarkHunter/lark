#pragma once
#include <winsock2.h>
#include <iostream>
#include <vector>
#include <thread>
#pragma comment(lib, "ws2_32.lib")  //���� ws2_32.dll

typedef std::vector<int> VecClientFd; // �����Ѿ������ϵĿͻ����׽���������

/*---------------------------------------------------------------------------
** ���� : SubServer
**---------------------------------------------------------------------------
** ���� : �ӷ�����
**---------------------------------------------------------------------------
** Date			Name
** 2018.02.06	��ΰ
**---------------------------------------------------------------------------*/
class SelectClient
{
public:

	// ��ʼ��
	SelectClient();

	// �ͷ�
	~SelectClient();

	// ��ʼ���������
	bool InitNetService();

private:

	// ��ʼ���׽���
	int InitSocket();

	// �����ͻ�������
	static bool DealNetRequest(int iServerfd);

private:

	static SelectClient * m_pSelectClient; // ��ѯ�ͻ�������ģ��

	VecClientFd m_VecClientFd; // �Ѿ������ϵĿͻ����׽���������

	std::thread *m_thSelectClient; // ��ѯ�ͻ��������߳�
};
