#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include<string>

class FileHandler{
    public:
        static bool FileRead(const std::string& inputPath,std::string& text);
        static bool FileWrite(const std::string& outputPath,const std::string& text);
};

#endif