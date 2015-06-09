/*************************************************************************
  > File Name: mb_socket_util.h
  > Author: yangtao
  > Mail: 280536669@qq.com 
  > Created Time: Sun 24 May 2015 12:50:04 PM HKT
 ************************************************************************/

#include "mb.h"

#ifndef _mb_socket_util_
#define _mb_socket_util_

namespace baselib
{
    class SocketUtil
    {
        private:
			enum {
				SUCC = 0,
				FAIL = -1
			};
			int Setsockopt(int fd, int level, int optname, const void *optval, socklen_t optlen);
		public:
			int SetSockNoblock(Socket &sock);
			int SetSockReUseAddr(Socket &sock);
	};
}

#endif
