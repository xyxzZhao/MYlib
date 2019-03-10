#include "Exception.h"
#include <cstring>
#include <cstdlib>

namespace MYlib
{

void Exception::init(const char* message, const char* file, int line)
{
    m_message = strdup(message);

    if(file != nullptr)
    {
        char sl[16] = {0};

        itoa(line, sl, 10); //将line数字以十进制转换成字符串，放在sl数组中

        m_location = static_cast<char*>( malloc(strlen(file) + strlen(sl) + 2) );

        if(m_location != nullptr)
        {
            m_location = strcpy(m_location, file);
            m_location = strcat(m_location, ":");
            m_location = strcat(m_location, sl);
        }
    }
    else
    {
        m_location = nullptr;
    }
}

Exception::Exception(const char* message)
{
    init(message, nullptr, 0);
}
Exception::Exception(const char* file, int line)
{
    init(nullptr, file, line);
}
Exception::Exception(const char* message, const char* file, int line)
{
    init(message, file, line);
}

/*在拷贝时，需要进行深拷贝*/
Exception::Exception(const Exception& e)
{
    m_message = strdup(e.m_message);
    m_location = strdup(e.m_location);
}
Exception& Exception::operator= (const Exception& e)
{
    if(this != &e)  //不是自赋值的情况
    {
        free(m_message);
        free(m_location);

        m_message = strdup(e.m_message);
        m_location = strdup(e.m_location);
    }

    return *this;
}

const char* Exception::message() const
{
    return m_message;
}
const char* Exception::location() const
{
    return m_location;
}

Exception::~Exception()
{
    free(m_message);
    free(m_location);
}

}
