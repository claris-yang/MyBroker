/*************************************************************************
    > File Name: mb_shared_pointer.h
    > Author: yangtao
    > Mail: 280536669@qq.com 
    > Created Time: Tue 09 Jun 2015 09:45:37 PM HKT
 ************************************************************************/
#ifndef _mb_shared_pointer_
#define _mb_shared_pointer_

#include "mb.h"

namespace mybroker
{

    /**
     * @brief 智能指针类
     *
     * @tparam ElementType 要求该类型有inc()和dec()两函数或继承自bgcc::Shareable类
     * @see
     * @note
     * @author  yangtao(280536669@qq.com)
     * @date    2015年06月09日 21时48分30秒
     */
    template <typename ElementType>
        class SharedPointer {
        public:
            /**
             * @brief SharedPointer 构造函数
             *
             * @param ptr 资源指针
             * @see
             * @note
			 * @author  yangtao(280536669@qq.com)
			 * @date    2015年06月09日 21时48分30秒
             */
            explicit SharedPointer(ElementType* ptr = NULL) : _pointer(ptr) {
                if (NULL != _pointer) {
                    _pointer->inc();
                }
            }

            /**
             * @brief SharedPointer 拷贝构造函数
             *
             * @param other SharedPointer引用
             * @see
             * @note
			 * @author  yangtao(280536669@qq.com)
			 * @date    2015年06月09日 21时48分30秒
             */
            SharedPointer(const SharedPointer &other) : _pointer(other._pointer) {
                if (NULL != _pointer) {
                    _pointer->inc();
                }
            }

            /**
             * @brief SharedPointer 拷贝构造函数
             *
             * @tparam U U为SharedPointer子类型
             * @param other other持有ElementType派生类的指针
             * @see
             * @note
			 * @author  yangtao(280536669@qq.com)
			 * @date    2015年06月09日 21时48分30秒
             */
            template <typename U>
                SharedPointer(const SharedPointer<U> &other) : _pointer(NULL) {
                    _pointer = other.get();
                    if (NULL != _pointer) {
                        _pointer->inc();
                    }
                }

            /**
             * @brief ~SharedPointer 构造函数，如果引用计数减为0，则释放资源
             * @see
             * @note
			 * @author  yangtao(280536669@qq.com)
			 * @date    2015年06月09日 21时48分30秒
             */
            ~SharedPointer() {
                if (NULL != _pointer) {
                    if (_pointer->dec() == 0) {
                        delete _pointer;
                        _pointer = NULL;
                    }
                }
            }

            /**
             * @brief operator= 赋值运算符
             *
             * @param r 赋值运算符右操作数
             *
             * @return 
             * @see
             * @note
			 * @author  yangtao(280536669@qq.com)
			 * @date    2015年06月09日 21时48分30秒
             */
            SharedPointer & operator=(const SharedPointer& r) {
                if(_pointer != r._pointer) { //已经判断(this != &r)
                    if (NULL != r._pointer) {
                        r._pointer->inc();
                    }

                    ElementType *ptr = _pointer;
                    _pointer = r._pointer;
                    if (NULL != ptr) {
                        if(ptr->dec() == 0){
                            delete ptr;
                            ptr = NULL;
                        }
                    }
                }

                return *this;
            }

            /**
             * @brief get 获取底层资源指针
             *
             * @return  底层资源指针
             * @see
             * @note
			 * @author  yangtao(280536669@qq.com)
			 * @date    2015年06月09日 21时48分30秒
             */
            ElementType* get() const {
                return _pointer;
            }

            /**
             * @brief operator-> 返回底层资源指针
             *
             * @return 资源指针
             * @see
             * @note
			 * @author  yangtao(280536669@qq.com)
			 * @date    2015年06月09日 21时48分30秒
             */
            ElementType* operator->() const {
                return _pointer;
            }

            /**
             * @brief operator 返回底层资源引用
             *
             * @return 资源引用
             * @see
             * @note
			 * @author  yangtao(280536669@qq.com)
			 * @date    2015年06月09日 21时48分30秒
             */
            ElementType& operator*() const {
                return *_pointer;
            }

            /**
             * @brief is_valid 判断本智能指针是否持有合法的资源
             *
             * @return 返回true，表示合法；否则，返回false 
             * @see
             * @note
			 * @author  yangtao(280536669@qq.com)
			 * @date    2015年06月09日 21时48分30秒
             */
            bool is_valid() const {
                return _pointer ? true : false;
            }

        private:
            ElementType* _pointer;  /** 底层资源指针*/
        };
}

#endif



