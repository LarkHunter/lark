#include <iostream>
#include "Client.h"
#include <windows.h>

int main()
{
	Client m_client;
	//m_client.StartNetService();
	m_client.StartNetServiceTest();

	m_client.SendBroadCast();
	system("pause");
	return 0;
}