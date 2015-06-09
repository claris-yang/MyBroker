/*************************************************************************
  > File Name: mb_service_socket.h
  > Author: yangtao
  > Mail: 280536669@qq.com 
  > Created Time: Sun 24 May 2015 12:50:04 PM HKT
 ************************************************************************/
#include "mb.h"

#ifndef _mb_service_socket_
#define _mb_service_socket_

namespace baselib
{
    class SocketService : public Socket
    {
        private:
			enum {
				SUCC = 0,
				FAIL = -1
			};
			int clientFd;
        public:
			int StartService();
			SocketService();
            virtual ~SocketService();  
    };
}

#endif
