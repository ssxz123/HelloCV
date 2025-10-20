#include"FileHandler.h"
#include<iostream>
#include<fstream>

bool FileHandler::FileRead(const std::string& inputPath,std::string& text){
    std::ifstream fin(inputPath);
    if(!fin.is_open()){
        std::cerr<<"无法打开输入文件！"<<std::endl;
        return false;
    }
    std::string line;
    while(getline(fin,line)){
        text+=line+'\n';
    }
    fin.close();
    return true;
}

bool FileHandler::FileWrite(const std::string& outputPath,const std::string& text){
    std::ofstream fout(outputPath);
    if(!fout.is_open()){
        std::cerr<<"无法创建输出文件！"<<std::endl;
        return false;
    }
    fout<<text;
    fout.close();
    return true;
}