#ifndef EXCEPTION_H
#define EXCEPTION_H

#include "Object.h"

namespace MYlib
{

class Exception : public Object
{

/*使用宏可以方便在当前文件当前行抛出异常*/
#define THROW_EXCEPTION(e,m) (throw e(m, __FILE__, __LINE__))

protected:
    char* m_message;    //用于说明异常的详细信息
    char* m_location;   //用于说明异常的发生地点

    void init(const char* message, const char* file, int line);
public:
    Exception(const char* message);
    Exception(const char* file, int line);
    Exception(const char* message, const char* file, int line);

    Exception(const Exception& e);
    Exception& operator= (const Exception& e);

    virtual const char* message() const;
    virtual const char* location() const;

    virtual ~Exception() = 0;
};

/***************
计算错误异常处理
例如：1/0
****************/
class ArithmeticException : public Exception
{
public:
    ArithmeticException() : Exception(nullptr) { }
    ArithmeticException(const char* message) : Exception(message) { }
    ArithmeticException(const char* file, int line) : Exception(file, line) { }
    ArithmeticException(const char* message, const char* file, int line) : Exception(message, file, line) { }

    ArithmeticException(const ArithmeticException& e) : Exception(e) { }

    ArithmeticException& operator= (const ArithmeticException& e)
    {
        Exception::operator=(e);

        return *this;
    }
};

/***************
空指针异常处理
例如：
****************/
class NullPointerException : public Exception
{
public:
    NullPointerException() : Exception(nullptr) { }
    NullPointerException(const char* message) : Exception(message) { }
    NullPointerException(const char* file, int line) : Exception(file, line) { }
    NullPointerException(const char* message, const char* file, int line) : Exception(message, file, line) { }

    NullPointerException(const NullPointerException& e) : Exception(e) { }

    NullPointerException& operator= (const NullPointerException& e)
    {
        Exception::operator=(e);

        return *this;
    }
};

/***************
越界异常处理
例如：数组越界
****************/
class IndexOutOfBoundsException : public Exception
{
public:
    IndexOutOfBoundsException() : Exception(nullptr) { }
    IndexOutOfBoundsException(const char* message) : Exception(message) { }
    IndexOutOfBoundsException(const char* file, int line) : Exception(file, line) { }
    IndexOutOfBoundsException(const char* message, const char* file, int line) : Exception(message, file, line) { }

    IndexOutOfBoundsException(const IndexOutOfBoundsException& e) : Exception(e) { }

    IndexOutOfBoundsException& operator= (const IndexOutOfBoundsException& e)
    {
        Exception::operator=(e);

        return *this;
    }
};

/***************
内存空间不足异常处理
例如：堆空间无法申请到足够的内存
****************/
class NoEnoughMemoryException : public Exception
{
public:
    NoEnoughMemoryException() : Exception(nullptr) { }
    NoEnoughMemoryException(const char* message) : Exception(message) { }
    NoEnoughMemoryException(const char* file, int line) : Exception(file, line) { }
    NoEnoughMemoryException(const char* message, const char* file, int line) : Exception(message, file, line) { }

    NoEnoughMemoryException(const NoEnoughMemoryException& e) : Exception(e) { }

    NoEnoughMemoryException& operator= (const NoEnoughMemoryException& e)
    {
        Exception::operator=(e);

        return *this;
    }
};

/***************
参数错误异常处理
例如：函数参数传入不正确的值
****************/
class InvalidParameterException : public Exception
{
public:
    InvalidParameterException() : Exception(nullptr) { }
    InvalidParameterException(const char* message) : Exception(message) { }
    InvalidParameterException(const char* file, int line) : Exception(file, line) { }
    InvalidParameterException(const char* message, const char* file, int line) : Exception(message, file, line) { }

    InvalidParameterException(const InvalidParameterException& e) : Exception(e) { }

    InvalidParameterException& operator= (const InvalidParameterException& e)
    {
        Exception::operator=(e);

        return *this;
    }
};

/***************
操作错误异常处理
例如：
****************/
class InvalidOperationException : public Exception
{
public:
    InvalidOperationException() : Exception(nullptr) { }
    InvalidOperationException(const char* message) : Exception(message) { }
    InvalidOperationException(const char* file, int line) : Exception(file, line) { }
    InvalidOperationException(const char* message, const char* file, int line) : Exception(message, file, line) { }

    InvalidOperationException(const InvalidOperationException& e) : Exception(e) { }

    InvalidOperationException& operator= (const InvalidOperationException& e)
    {
        Exception::operator=(e);

        return *this;
    }
};
}

#endif // EXCEPTION_H
