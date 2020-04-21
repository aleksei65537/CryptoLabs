#include "vigenere.hpp"
#include <iostream>
#include <string>

int main() 
{
    std::string answer;
    std::string message;
    std::string key;

    while(true) 
    {
        std::cout <<
            ">>> Choose operation: encrypt (e), decrypt (d) or exit (q): ";
        std::getline(std::cin, answer);

        if (answer == "e") 
        {
            std::cout << ">>> Enter a message for encryption: ";
            std::getline(std::cin, message);
            std::cout << ">>> Enter a key: ";
            std::getline(std::cin, key);
            std::cout << ">>> Your encrypted message: " <<
                Vigenere(key).encrypt(message) << std::endl;
            std::cout << ">>> (Press enter to continue)";
            std::cin.get();
        }

        if (answer == "d") 
        {
            std::cout << ">>> Enter a message for decryption: ";
            std::getline(std::cin, message);
            std::cout << ">>> Enter a key: ";
            std::getline(std::cin, key);
            std::cout << ">>> Your decrypted message: " <<
                Vigenere(key).decrypt(message) << std::endl;
            std::cout << ">>> (Press enter to continue)";
            std::cin.get();
            std::cout << std::endl;
        }

        if (answer == "q") 
        {
            std::cout << ">>> Good Buy!" << std::endl;
            exit(0);
        }
        else continue;
    }

    return 0;
}
