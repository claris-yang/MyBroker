/*************************************************************************
    > File Name: mb_shareable.cpp
    > Author: yangtao
    > Mail: 280536669@qq.com 
    > Created Time: Tue 09 Jun 2015 10:38:44 PM HKT
 ************************************************************************/

#include "mb_shareable.h"

namespace mybroker{
    typedef Guard<Mutex> ScopedGuard;

    Shareable::Shareable() : _count(0) { }

    void Shareable::inc() {
        ScopedGuard guard(&_mutex);
        ++_count;
    }

    int32_t Shareable::dec() {
        ScopedGuard guard(&_mutex);

        if (_count > 0) {
            --_count;
        }
        return _count;
    }

    int32_t Shareable::get_count() {
        ScopedGuard guard(&_mutex);
        return _count;
    }
}

