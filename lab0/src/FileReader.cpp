#include <iostream>


#include "../include/FileReader.h"

bool FileReader::openInputFile(const std::string& FilePath){
    inputFile.open(FilePath);
    return inputFile.is_open();
}
bool FileReader::readline(std::string& line){
    auto& state = getline(inputFile, line);
    return state? true:false;
}