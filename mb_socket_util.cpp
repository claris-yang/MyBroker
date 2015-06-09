/*************************************************************************
  > File Name: mb_socket_util.cpp
  > Author: yangtao
  > Mail: 280536669@qq.com 
  > Created Time: Sun 24 May 2015 12:50:04 PM HKT
 ************************************************************************/

#include "mb_socket_util.h"

int SocketUtil::Setsockopt(int fd, int level, int optname, const void *optval, socklen_t optlen)
{
	int iRet;
	if ((iRet = setsockopt(fd, level, optname, optval, optlen)) < 0)
	{
		err_sys("setsockopt error");
		return FAIL;
	}
	
	return SUCC;
}

int SocketUtil::SetSockNoblock(Socket &sock)
{
	int fd = sock.GetSocket();
	return SUCC;
}

int SocketUtil::SetSockReUseAddr(Socket &sock)
{
	int fd = sock.GetSocket();
	int reUse = 1;
	int iRet;
	if ((iRet = Setsockopt( fd , SOL_SOCKET , SO_REUSEADDR , (char *)&reUse, sizeof(reUse))) == FAIL)
	{
		err_sys("setsockopt error");
		return FAIL;
	}
}
