/*************************************************************************
    > File Name: master.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Sat 23 May 2015 02:45:05 PM HKT
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include"master.h"
#include "stream_socket_factory.h"
using namespace std;


int main(int argc, char *argv[])
{
	AbsSocketFactory *factory = new StreamSocketFactory(8888);
	
	ServSocket * sock = factory->getServSocket();

	sock->_accept();

	if( argc > 0 )
		printf( " %d, %s ", argc , argv[0]);

	return 0;
}



