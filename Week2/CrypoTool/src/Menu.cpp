#include"Crypto.h"
#include"FileHandler.h"
#include"Menu.h"
#include<iostream>
#include<cstdlib>
#include<iomanip>

void Menu::ScreenClear() {
    static bool firstCall = true;
    static int startLine = 0;
        
    if (firstCall) {
        // 第一次调用时，记录程序开始位置
        std::cout << "\033[s";  // 保存光标位置
        firstCall = false;
        } else {
        // 后续调用时，恢复到程序开始位置并清除到屏幕末尾
        std::cout << "\033[u";  // 恢复光标位置
        std::cout << "\033[0J"; // 清除从光标到屏幕末尾
    }
}

bool Menu::StartMenu(){
    ScreenClear();
    std::cout<<"===文本加密解密工具==="<<std::endl;
    std::cout<<"1.文本加密"<<std::endl;
    std::cout<<"2.文本解密"<<std::endl;
    std::cout<<"3.文件加密"<<std::endl;
    std::cout<<"4.文件解密"<<std::endl;
    std::cout<<"5.退出"<<std::endl;
    std::cout<<"请选择:(1~5)"<<std::endl;
    std::string OP;
    int op;
    getline(std::cin,OP);
    try{
        op=stoi(OP);
    }
    catch(const std::exception& e){
        std::cerr<<"输入格式错误！"<<std::endl;
        std::cout<<"输入回车后返回...";
        std::cin.get();
        return true;
    }
    if(op==5)return false;
    else if(op>=1&&op<=4) ChooseMenu(op);
    else {
        std::cout<<"输入格式错误！"<<std::endl;
        std::cout<<"输入回车后返回...";
        std::cin.get();
    }
    return true;
}

void Menu::ChooseMenu(int Type){
    ScreenClear();
    std::cout<<"===文本加密解密工具==="<<std::endl;
    std::cout<<"请选择加密/解密方式："<<std::endl;
    std::cout<<"1.凯撒密码"<<std::endl;
    std::cout<<"2.XOR加密"<<std::endl;
    std::cout<<"3.返回"<<std::endl;
    std::cout<<"请选择:(1~3)"<<std::endl;
    std::string CTYPE;
    getline(std::cin,CTYPE);
    try{
        CryptType=std::stoi(CTYPE);
    }
    catch(const std::exception& e){
        std::cerr<<"输入格式错误！"<<std::endl;
        std::cout<<"输入回车后返回...";
        std::cin.get();
        return;
    }
    if(CryptType==3)return;
    switch(Type){
        case 1:
            encryptText();
            break;
        case 2:
            decryptText();
            break;
        case 3:
            encryptFile();
            break;
        case 4:
            decryptFile();
            break;
        default:
            std::cout<<"输入格式错误！"<<std::endl;
            std::cout<<"输入回车后返回...";
            std::cin.get();
            break;
    }

}

void Menu::encryptText(){
    ScreenClear();
    std::string text,result,strkey;
    std::cout<<"===文本加密解密工具==="<<std::endl;
    std::cout<<"请输入要加密的文本：";
    getline(std::cin,text);
    std::cout<<"请输入密钥：";
    getline(std::cin,strkey);

    try{
        if(CryptType == 1){
            result=Crypto::caesarEncrypt(text,std::stoi(strkey));
        }
        else if(CryptType == 2){
            result=Crypto::stringTohex(Crypto::xorEncrypt(text,strkey)); 
        }
        std::cout<<"加密结果："<<result<<std::endl;
    }
    catch(const std::exception& e){
        std::cerr<<"输入格式错误！"<<std::endl;
    }
    std::cout<<"输入回车后返回...";
    std::cin.get();
}

void Menu::decryptText(){
    ScreenClear();
    std::string text,result,strkey;
    std::cout<<"===文本加密解密工具==="<<std::endl;
    std::cout<<"请输入要解密的文本：";
    getline(std::cin,text);
    std::cout<<"请输入密钥：";
    getline(std::cin,strkey);
    try{
        if(CryptType == 1){
            result=Crypto::caesarDecrypt(text,std::stoi(strkey));
        }
        else if(CryptType == 2){
            result=Crypto::stringTohex(Crypto::xorDecrypt(text,strkey)); 
        }
        std::cout<<"解密结果："<<result<<std::endl;
    }
    catch(const std::exception& e){
        std::cerr<<"输入格式错误！"<<std::endl;
    }
    std::cout<<"输入回车后返回...";
    std::cin.get();
}

void Menu::encryptFile(){
    ScreenClear();
    std::string inputPath,text,strkey,outputPath="encrypted.txt";
    std::cout<<"===文本加密解密工具==="<<std::endl;
    std::cout<<"请输入要加密的文件路径：";
    getline(std::cin,inputPath);
    if(FileHandler::FileRead(inputPath,text)==false){
        std::cout<<"输入回车后返回...";
        std::cin.get();
        return;
    }
    std::cout<<"请输入密钥：";
    getline(std::cin,strkey);
    try{
        if(CryptType==1){
            FileHandler::FileWrite(outputPath,Crypto::caesarEncrypt(text,std::stoi(strkey)));
        }
        else if(CryptType == 2){
            FileHandler::FileWrite(outputPath,Crypto::stringTohex(Crypto::xorEncrypt(text,strkey)));
        }
        std::cout<<"加密结果已保存到："<<outputPath<<std::endl;
    }
    catch(const std::exception& e){
        std::cerr<<"输入格式错误！"<<std::endl;
    }
    
    std::cout<<"输入回车后返回...";
    std::cin.get();
}

void Menu::decryptFile(){
    ScreenClear();
    std::string inputPath,text,strkey,outputPath="decrypted.txt";
    std::cout<<"===文本加密解密工具==="<<std::endl;
    std::cout<<"请输入要解密的文件路径：";
    getline(std::cin,inputPath);
    if(FileHandler::FileRead(inputPath,text)==false){
        std::cout<<"无法打开文件！输入回车后返回...";
        std::cin.get();
        return;
    }
    std::cout<<"请输入密钥：";
    getline(std::cin,strkey);
    try{
        if(CryptType==1){
            FileHandler::FileWrite(outputPath,Crypto::caesarDecrypt(text,std::stoi(strkey)));
        }
        else if(CryptType == 2){
            FileHandler::FileWrite(outputPath,Crypto::xorDecrypt(Crypto::hexTostring(text),strkey));
            std::cout<<Crypto::xorDecrypt(Crypto::hexTostring(text),strkey)<<std::endl;
        }
        std::cout<<"解密结果已保存到："<<outputPath<<std::endl;
    }
    catch(const std::exception& e){
        std::cerr<<"输入格式错误！"<<std::endl;
    }
    std::cout<<"输入回车后返回...";
    std::cin.get();
}

void Menu::run(){
    while(StartMenu());
    ScreenClear();
    std::cout<<"感谢使用本工具！"<<std::endl;
}