#include<iostream>
#include "SubServer.h"
#include<windows.h>


int main()
{
	std::cout << "..."<<std::endl;

	SubServer m_subServer;
	m_subServer.InitNetService();

	system("pause");

	return 0;
}
