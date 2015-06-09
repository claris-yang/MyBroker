/*************************************************************************
    > File Name: mb_shareable.h
    > Author: yangtao
    > Mail: 280536669@qq.com 
    > Created Time: Tue 09 Jun 2015 10:27:08 PM HKT
 ************************************************************************/

#ifndef _MB_SHAREABLE_
#define _MB_SHAREABLE_

#include "mb.h"

namespace mybroker{

    /**
     * @brief 提供具有原子增减的通用计数器功能，可被多个智能指针对象共享
     * @see
     * @note
     * @author  yangtao(280536669@qq.com)
     * @date    2015年06月09日 22时29分25秒
     */
    class Shareable {
    public:
        /**
         * @brief ~Shareable 析构函数
         * @see
         * @note
		 * @author  yangtao(280536669@qq.com)
         * @date    2015年06月09日 22时29分25秒
         */
        virtual ~Shareable() { }

        /**
         * @brief inc 增加引用计数
         * @see
         * @note
		 * @author  yangtao(280536669@qq.com)
         * @date    2015年06月09日 22时29分25秒
         */
        void inc();

        /**
         * @brief dec 减少引用计数
         *
         * @return 引用计数减1后的值
         * @see
         * @note
		 * @author  yangtao(280536669@qq.com)
         * @date    2015年06月09日 22时29分25秒
         */
        int32_t dec();

        /**
         * @brief get_count 获取当前引用计数
         *
         * @return 当前引用计数值
         * @see
         * @note
		 * @author  yangtao(280536669@qq.com)
         * @date    2015年06月09日 22时29分25秒
         */
        int32_t get_count();
    protected:
        /**
         * @brief Shareable 禁用显式构造，仅可通过子类构造
         * @see
         * @note
		 * @author  yangtao(280536669@qq.com)
         * @date    2015年06月09日 22时29分25秒
         */
        Shareable();
    private:
        int32_t _count;
        Mutex _mutex;
    private:
        /**
         * @brief Shareable 禁用拷贝构造功能
         *
         * @param Shareable
         * @see
         * @note
		 * @author  yangtao(280536669@qq.com)
         * @date    2015年06月09日 22时29分25秒
         */
        Shareable(const Shareable&);

        /**
         * @brief operator= 禁用赋值运算符
         *
         * @param Shareable
         *
         * @return 
         * @see
         * @note
		 * @author  yangtao(280536669@qq.com)
         * @date    2015年06月09日 22时29分25秒
         */
        Shareable& operator=(const Shareable&);
    };
}

#endif // _MB_SHAREABLE_

