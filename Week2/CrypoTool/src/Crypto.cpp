#include"Crypto.h"
#include<cctype>
#include<iomanip>
#include<sstream>
#include<iostream>

std::string Crypto::caesarEncrypt(const std::string& text,const int key){
    std::string res=text;
    for(int i=0;i<res.size();i++){
        if(isalpha(res[i])){
            char base=std::isupper(res[i])?'A':'a';
            res[i]=(res[i]-base+key)%26+base;
        }
    }
    return res;
}

std::string Crypto::caesarDecrypt(const std::string& text,const int key){
    return caesarEncrypt(text,26-key%26);
}

std::string Crypto::xorEncrypt(const std::string& text,const std::string& key){
    std::string res=text;
    int key_size=key.size();
    for(int i=0;i<res.size();i++){
        res[i]=res[i]^key[i%key_size];
    }
    return res;
}

std::string Crypto::xorDecrypt(const std::string& text,const std::string& key){
    return xorEncrypt(text,key);
}

// 将十六进制字符串转换为普通字符串
std::string Crypto::hexTostring(const std::string& hex) {
    std::string result;
    
    for (int i = 0; i < hex.size(); i += 2) {
        if (i + 1 < hex.size()) {
            std::string byteString = hex.substr(i, 2);
            unsigned char byte = (unsigned char) strtol(byteString.c_str(), nullptr, 16);
            result += byte;
        }
    }
    return result;
}

// 将字符串转换为十六进制格式
std::string Crypto::stringTohex(const std::string& data) {
    std::stringstream ss;
    
    for (unsigned char c : data) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)c;
    }
    
    return ss.str();
}