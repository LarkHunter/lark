#include <iostream>
#include "Client.h"
#include <windows.h>

int main()
{
	Client m_client;
	m_client.StartNetService();

	system("pause");
	return 0;
}