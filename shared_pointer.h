/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_SHARED_POINTER_H_
#define _BGCC2_SHARED_POINTER_H_

#include "bgcc_common.h"

namespace bgcc {

    /**
     * @brief ����ָ����
     *
     * @tparam ElementType Ҫ���������inc()��dec()��������̳���bgcc::Shareable��
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012��06��13�� 15ʱ19��35��
     */
    template <typename ElementType>
        class SharedPointer {
        public:
            /**
             * @brief SharedPointer ���캯��
             *
             * @param ptr ��Դָ��
             * @see
             * @note
             * @author  liuxupeng(liuxupeng@baidu.com)
             * @date    2012��06��13�� 14ʱ33��20��
             */
            explicit SharedPointer(ElementType* ptr = NULL) : _pointer(ptr) {
                if (NULL != _pointer) {
                    _pointer->inc();
                }
            }

            /**
             * @brief SharedPointer �������캯��
             *
             * @param other SharedPointer����
             * @see
             * @note
             * @author  liuxupeng(liuxupeng@baidu.com)
             * @date    2012��06��13�� 15ʱ13��35��
             */
            SharedPointer(const SharedPointer &other) : _pointer(other._pointer) {
                if (NULL != _pointer) {
                    _pointer->inc();
                }
            }

            /**
             * @brief SharedPointer �������캯��
             *
             * @tparam U UΪSharedPointer������
             * @param other other����ElementType�������ָ��
             * @see
             * @note
             * @author  liuxupeng(liuxupeng@baidu.com)
             * @date    2012��06��13�� 15ʱ14��17��
             */
            template <typename U>
                SharedPointer(const SharedPointer<U> &other) : _pointer(NULL) {
                    _pointer = other.get();
                    if (NULL != _pointer) {
                        _pointer->inc();
                    }
                }

            /**
             * @brief ~SharedPointer ���캯����������ü�����Ϊ0�����ͷ���Դ
             * @see
             * @note
             * @author  liuxupeng(liuxupeng@baidu.com)
             * @date    2012��06��13�� 15ʱ15��16��
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
             * @brief operator= ��ֵ�����
             *
             * @param r ��ֵ������Ҳ�����
             *
             * @return 
             * @see
             * @note
             * @author  liuxupeng(liuxupeng@baidu.com)
             * @date    2012��06��13�� 15ʱ15��53��
             */
            SharedPointer & operator=(const SharedPointer& r) {
                if(_pointer != r._pointer) { //�Ѿ��ж�(this != &r)
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
             * @brief get ��ȡ�ײ���Դָ��
             *
             * @return  �ײ���Դָ��
             * @see
             * @note
             * @author  liuxupeng(liuxupeng@baidu.com)
             * @date    2012��06��13�� 15ʱ16��21��
             */
            ElementType* get() const {
                return _pointer;
            }

            /**
             * @brief operator-> ���صײ���Դָ��
             *
             * @return ��Դָ��
             * @see
             * @note
             * @author  liuxupeng(liuxupeng@baidu.com)
             * @date    2012��06��13�� 15ʱ17��41��
             */
            ElementType* operator->() const {
                return _pointer;
            }

            /**
             * @brief operator ���صײ���Դ����
             *
             * @return ��Դ����
             * @see
             * @note
             * @author  liuxupeng(liuxupeng@baidu.com)
             * @date    2012��06��13�� 15ʱ18��09��
             */
            ElementType& operator*() const {
                return *_pointer;
            }

            /**
             * @brief is_valid �жϱ�����ָ���Ƿ���кϷ�����Դ
             *
             * @return ����true����ʾ�Ϸ������򣬷���false 
             * @see
             * @note
             * @author  liuxupeng(liuxupeng@baidu.com)
             * @date    2012��06��13�� 15ʱ18��46��
             */
            bool is_valid() const {
                return _pointer ? true : false;
            }

        private:
            ElementType* _pointer;  /** �ײ���Դָ��*/
        };
}
#endif // _BGCC2_SHARED_POINTER_H_

