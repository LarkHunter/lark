#include <iostream>
//#include "ConnectLoginServer.h"
#include "SelectClient.h"
#include <windows.h>

int main()
{
// 	ConnectLoginServer m_SubServer;
 	SelectClient m_SelectClient;
// 
// 	bool bResult = m_SubServer.StartNetService();

	bool bResult = true;
	if(bResult)
	{
		m_SelectClient.InitNetService();
	}
	

	system("pause");

	return 0;
}