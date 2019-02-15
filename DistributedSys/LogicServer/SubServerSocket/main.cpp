#include <iostream>
#include "ConnectLoginServer.h"
#include "SelectClient.h"
#include <windows.h>

int main()
{
	ConnectLoginServer m_SubServer;
	m_SubServer.StartNetService();

	SelectClient m_SelectClient;
	m_SelectClient.InitNetService();

	std::cout <<"......." << std::endl;
	//system("pause");

	return 0;
}