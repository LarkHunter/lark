#include <iostream>
#include "SubServerSocket.h"
#include <windows.h>

int main()
{
	SubServer m_SubServer;
	m_SubServer.StartSubServer();

	system("pause");

	return 0;
}