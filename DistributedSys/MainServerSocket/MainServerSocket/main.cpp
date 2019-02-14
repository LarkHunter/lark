#include <iostream>
#include "AcceptServerSocket.h"
#include "SelectClientSocket.h"
/*using namespace std;*/

int main()
{
	AcceptServerSocket m_MainServer;
	SelectClientSocket m_SelectClient;

	m_MainServer.StartNetService();
	//m_SelectClient.StartNetService();

	return 0;
}