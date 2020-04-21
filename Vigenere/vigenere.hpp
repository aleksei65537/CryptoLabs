#pragma once

#include <string>
#include <stdexcept>

class Vigenere 
{
    private:
        std::string key;
        void add_chiper_char(std::string& s, const char m, const char k);
        void add_dechiper_char(std::string& s, const char c, const char k);
        char get_rel_code(const char c);
        char get_abs_code(const char c);

    public:
        Vigenere() = delete;
        ~Vigenere() { }

        Vigenere(const std::string& key_) 
        {
            for (const auto& it: key_) 
            {
                if (!std::isalpha(it)) 
                {
                    throw std::invalid_argument(
                            "Key must be an aplphabetic string"
                            );
                }
                else 
                {
                    key = key_;
                }
            }
        }

        std::string encrypt(const std::string& message);
        std::string decrypt(const std::string& chipertext);
        void change_key(const std::string& key_) { key = key_; }

};

inline
char Vigenere::get_rel_code(const char c) 
{
    return std::toupper(c) - 'A';
}

inline
char Vigenere::get_abs_code(const char c) {
    return c + 'A';
}
