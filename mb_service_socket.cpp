/*************************************************************************
  > File Name: mb_service_socket.cpp
  > Author: yangtao
  > Mail: 280536669@qq.com 
  > Created Time: Sun 24 May 2015 12:50:04 PM HKT
 ************************************************************************/
#include "mb_service_socket.h"
using namespace baselib;

int SocketService::StartService()
{
	if(Bind(9999) == FAIL)
	{
		return FAIL;	
	}
	
	if(Listen() == FAIL)
	{
		return FAIL;
	}

	if((clientFd = Accept()) == FAIL)
	{
		return FAIL;
	}

	return SUCC;
}

