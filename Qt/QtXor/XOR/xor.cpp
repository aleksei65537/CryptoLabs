#include "xor.hpp"

std::string crypt(const std::string& message,
                  const std::vector<std::string>& keys)
{
    std::string result("", message.size()); 

    for (const auto& s : keys)
    {
        for(size_t i = 0; i < message.size(); i++)
        {
            result[i] = s[i % s.size()] ^ message[i];
        }
    }

    return result;
}
