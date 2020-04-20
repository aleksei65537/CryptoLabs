#include "vigenere.hpp"

void Vigenere::add_chiper_char(std::string& s, const char m, const char k) {
    bool lower = false;

    if (std::islower(m)) {
       lower = true;
    }

    s += (get_rel_code(m) + get_rel_code(k)) % 26;
    s.back() = get_abs_code(s.back());

    if(lower) {
        s.back() = std::tolower(s.back());
    }
}

void Vigenere::add_dechiper_char(std::string& s, const char c, const char k) {
    bool lower = false;

    if (std::islower(c)) {
       lower = true;
    }

    s += (get_rel_code(c) + 26 - get_rel_code(k)) % 26;
    s.back() = get_abs_code(s.back());

    if(lower) {
        s.back() = std::tolower(s.back());
    }
}

std::string Vigenere::encrypt(const std::string& message) {
    std::string chipertext;
    int j = 0;

    for (size_t i = 0; i < message.size(); i++) {

        if (std::isalpha(message[i])) {
            add_chiper_char(chipertext, message[i], key[j % key.size()]);
            ++j;
        }
        else {
            chipertext += message[i];
        }
    }
    return chipertext;
}

std::string Vigenere::decrypt(const std::string& chipertext) {
    std::string message;
    int j = 0;

    for (size_t i = 0; i < chipertext.size(); i++) {

        if (std::isalpha(chipertext[i])) {
            add_dechiper_char(message, chipertext[i], key[j % key.size()]);
            ++j;
        }
        else {
            message += chipertext[i];
        }
    }
    return message;
}
