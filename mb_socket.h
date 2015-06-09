/*************************************************************************
  > File Name: mb_socket.h
  > Author: yangtao
  > Mail: 280536669@qq.com 
  > Created Time: Sun 24 May 2015 12:50:04 PM HKT
 ************************************************************************/
#include "mb.h"

#ifndef _mb_socket_
#define _mb_socket_

namespace baselib
{
	class Socket
	{
		private:
			int domain;
			int type;
			int protocal;
		protected:
			int fd;
			struct sockaddr_in serviceAddr;
			socklen_t servAddrLen;
			int servicePort;           
			struct sockaddr_in clientAddr;
			socklen_t cliAddrLen;
			int clientPort;
			virtual int Bind(int iPort);
			virtual int Listen() ;
			virtual int Accept();
			virtual int Connect(const char* cIp, int iPort);
		public:
			Socket();
			Socket(int _domain , int _type, int _protocal);
			int GetSocket();
			virtual ~Socket();	
	};
}

#endif
