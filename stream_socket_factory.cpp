/*************************************************************************
    > File Name: stream_socket_factory.cpp
    > Author: yangtao 
    > Mail: 280536669@qq.com 
    > Created Time: Sun 24 May 2015 12:50:50 PM HKT
 ************************************************************************/

#include "stream_socket_factory.h"

Socket * StreamSocketFactory::getSocket()
{
//	bgcc::SharedPointer< Socket > sock_ptr( new Socket( AF_INET, SOCK_STREAM, 0 ));
	Socket *sock_ptr = new Socket( AF_INET, SOCK_STREAM, 0 ) ;

	return sock_ptr;
}


ServSocket* StreamSocketFactory::getServSocket()
{
	ServSocket *sock_ptr = new ServSocket( AF_INET, SOCK_STREAM, 0 ) ;

	sock_ptr->_bind( _port);

	sock_ptr->_listen();

	return sock_ptr;
}

CliSocket* StreamSocketFactory::getCliSocket()
{
	CliSocket *sock_ptr = new CliSocket( AF_INET, SOCK_STREAM, 0 ) ;
	return sock_ptr;
}
