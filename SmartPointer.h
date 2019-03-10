#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H


#include "Object.h"

namespace MYlib
{

template <typename T>
class SmartPointer : public Object
{
protected:
    T* m_pointer;

public:
    SmartPointer(T* p =nullptr);
    SmartPointer(const SmartPointer<T>& obj);
    SmartPointer<T>& operator= (const SmartPointer<T>& obj);
    T* operator-> ();
    T& operator* ();
    bool isNull();
    T* get();
    ~SmartPointer();
};

/*类模板只能在头文件中定义，不能像通常类那样分开实现!!!*/
template <typename T>
SmartPointer<T>::SmartPointer(T* p)
{
    m_pointer = p;
}

template <typename T>
SmartPointer<T>::SmartPointer(const SmartPointer<T>& obj)
{
    m_pointer = obj.m_pointer;
    const_cast<SmartPointer<T>&>(obj).m_pointer = nullptr;
}

template <typename T>
SmartPointer<T>& SmartPointer<T>::operator= (const SmartPointer<T>& obj)
{
    if(this != &obj)
    {
        delete m_pointer;
        m_pointer = obj.m_pointer;
        const_cast<SmartPointer<T>&>(obj).m_pointer = nullptr;
    }
    return *this;
}

template <typename T>
T* SmartPointer<T>::operator-> ()
{
    return m_pointer;
}

template <typename T>
T& SmartPointer<T>::operator* ()
{
    return *m_pointer;
}

template <typename T>
bool SmartPointer<T>::isNull()
{
    return (m_pointer == nullptr);
}

template <typename T>
T* SmartPointer<T>::get()
{
    return m_pointer;
}

template <typename T>
SmartPointer<T>::~SmartPointer()
{
    delete m_pointer;
}

}

#endif // SMARTPOINTER_H
