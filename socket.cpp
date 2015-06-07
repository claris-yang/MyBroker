/*************************************************************************
  > File Name: socket.cpp
  > Author: yangtao
  > Mail: 280536669@qq.com 
  > Created Time: Sun 24 May 2015 12:50:04 PM HKT
 ************************************************************************/

#include<iostream>
#include"socket.h"
using namespace std;

int CliSocket::_connect(const char* cliip, int port)
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

	if (connect(_fd, (SA *)&servAddr, servAddrLen) < 0)
		 err_sys("connect error");
	return 0;
}

Socket::Socket(int domain, int type, int protocal) : 
	_domain(domain), _type(type), _protocal(protocal)
{
	int fd;

	fd = socket( _domain, _type , _protocal );
	if(-1 == fd)
	{
		err_sys("socket error");
	}
	this->_fd = fd;

}

Socket::~Socket()
{
	close(_fd);
}

int Socket::getSocket()
{
	return this->_fd;
}

ServSocket::ServSocket (int domain, int type, int protocal)
{
	Socket sock = Socket(domain, type, protocal);
	this->_fd = sock.getSocket();
}


CliSocket::CliSocket(int domain, int type, int protocal)
{
	Socket sock = Socket(domain, type, protocal);
	this->_fd = sock.getSocket();
}

int ServSocket::_bind(int port)
{
	int fd = this->_fd;
	int iRet;

	struct sockaddr_in addr;

	memset( &addr, 0x00, sizeof(addr) );

	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(port);

	if ( -1 == (iRet = bind ( fd, (SA *)&addr, sizeof(addr) ) ))
	{
		err_sys("bind error");
	}

	return iRet;
}

int ServSocket::_listen()
{
	int fd = this->_fd;
	int iRet;

	iRet = listen( fd, 1000 );
	if(-1 == iRet)
	{
		err_sys("listen error");
	}

	return iRet;
}


int ServSocket::_accept( )
{
	int     n;
again:
	memset(&this->cliAddr, 0x00, sizeof(&this->cliAddr));
	this->cliAddrLen = 0;
	//if ( (n = accept(this->_fd,(SA *) &(this->cliAddr), &(this->cliAddrLen))) < 0) {
	if ( (n = accept(this->_fd, NULL, NULL)) < 0) {
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
