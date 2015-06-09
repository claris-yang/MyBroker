/*************************************************************************
   > File Name: mb_error.h
   > Author: yangtao
   > Mail: 280536669@qq.com 
   > Created Time: Sun 24 May 2015 12:50:04 PM HKT
  ************************************************************************/

#include "mb.h"

#ifndef _mb_error_
#define _mb_error_


void err_sys(const char *fmt, ...);

void err_doit(int errnoflag, int level, const char *fmt, va_list ap);

#endif
