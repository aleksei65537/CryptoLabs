#include "crc.hpp"

long long crc(std::string message)
{
    long long res = 0;
    long long gen = 0x13;   // порождающий полином
    long long limit = 0x10;  // ограничитель буфера
    
    for(size_t i = 0; i < message.size(); i++)
    {
        for(size_t j = 0; j < 8; j++)
        {
            if (res & limit) // буфер заполнен, нужно ксорить
            {
                res ^= gen;
            }

            if (message[i] & 0x80) // старший бит равен единице
            {
                res <<= 1;
                res += 1;
            }

            else
            {
                res <<=1;
            }

            message[i] <<= 1;           
        }
    }

    return res;
}
