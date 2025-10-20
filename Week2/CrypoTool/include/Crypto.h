#ifndef CRYPYO_H
#define CRYPYO_H

#include<string>

class Crypto{
    public:
        static std::string caesarEncrypt(const std::string& text,const int key);
        static std::string caesarDecrypt(const std::string& text,const int key);
        static std::string xorEncrypt(const std::string& text,const std::string& key);
        static std::string xorDecrypt(const std::string& text,const std::string& key);
        static std::string hexTostring(const std::string& hex);
        static std::string stringTohex(const std::string& data);
};

#endif