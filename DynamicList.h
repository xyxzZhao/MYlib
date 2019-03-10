#ifndef DYNAMICLIST_H
#define DYNAMICLIST_H

#include "SeqList.h"

namespace MYlib
{

template <typename T>
class DynamicList : public SeqList<T>
{
protected:
    int m_capacity; //顺序存储空间的大小
public:
    DynamicList(int capacity)
    {
        this->m_array = new T[capacity];

        if(this->m_array != nullptr)
        {
            this->m_length = 0;
            this->m_capacity = capacity;
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException,"No memory to creat DynamicList object ...");
        }

    }

    int capacity() const
    {
        return m_capacity;
    }
    /*重新设置存储空间的大小*/
    void resize(int capacity)
    {
        if(capacity != m_capacity)
        {
            T* array = new T[capacity];

            if(array != nullptr)
            {
                int length = (this->m_length < capacity ? this->m_length : capacity);

                for (int i = 0; i<length; i++)
                {
                    array[i] = this->m_array[i];
                }

                T* temp = this->m_array;

                this->m_array = array;
                this->m_length = length;
                this->m_capacity = capacity;

                delete [] temp;
            }
            else
            {
                THROW_EXCEPTION(NoEnoughMemoryException,"No memory to resize DynamicList object ...");
            }
        }
    }
    ~DynamicList()   //归还空间
    {
        delete [] this->m_array;
    }
};
}
#endif // DYNAMICLIST_H
