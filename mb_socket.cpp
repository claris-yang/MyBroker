/*************************************************************************
  > File Name: mb_socket.cpp
  > Author: yangtao
  > Mail: 280536669@qq.com 
  > Created Time: Sun 24 May 2015 12:50:04 PM HKT
 ************************************************************************/
#include "mb_socket.h"
using namespace baselib;

int Socket::GetSocket()
{
	return this->fd;
}

Socket::Socket()
{
	fd = socket( AF_INET , SOCK_STREAM , 0 );
	if(-1 == fd)
	{
		err_sys("socket error");
	}
}

int Socket::Bind(int iPort)
{   
    int iRet;                                         
                                                      
    memset( &serviceAddr, 0x00, sizeof(serviceAddr) );

    serviceAddr.sin_family = AF_INET;
    serviceAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serviceAddr.sin_port = htons(iPort);

    if ( -1 == (iRet = bind( fd, (SA *)&serviceAddr, sizeof(serviceAddr) ) ))
    {
        err_sys("bind error");
    }

    return iRet;
}

int Socket::Connect(const char* cliip, int port)
{

	struct sockaddr_in servAddr;
	int n; 
	socklen_t servAddrLen;

	memset(&servAddr, 0x00 ,sizeof(servAddr));

	servAddr.sin_port = htons(port);	
	if(( n = inet_pton(AF_INET, cliip, &servAddr.sin_addr)) < 0)
	{
		err_sys("inet_pton error for %s", cliip);
	}else
	{
		return -1;
	}

	servAddrLen = sizeof(servAddr);

	if (connect(fd, (SA *)&servAddr, servAddrLen) < 0)
		 err_sys("connect error");
	return 0;
}

Socket::Socket(int _domain, int _type, int _protocal) : 
	domain(_domain), type(_type), protocal(_protocal)
{
	fd = socket( _domain, _type , _protocal );
	if(-1 == fd)
	{
		err_sys("socket error");
	}
}

Socket::~Socket()
{
	close(fd);
}

int Socket::Listen()
{
	int fd = this->fd;
	int iRet;

	iRet = listen( fd, 1000 );
	if(-1 == iRet)
	{
		err_sys("listen error");
	}

	return iRet;
}


int Socket::Accept( )
{
	int     n;
again:
	memset(&clientAddr, 0x00, sizeof(&clientAddr));
	cliAddrLen = sizeof(clientAddr);
	if ( (n = accept(this->fd,(SA *) &clientAddr , &cliAddrLen)) < 0) {
#ifdef  EPROTO
		if (errno == EPROTO || errno == ECONNABORTED)
#else
			if (errno == ECONNABORTED)
#endif
				goto again;
			else
				err_sys("accept error");
	}
	return(n);
}
