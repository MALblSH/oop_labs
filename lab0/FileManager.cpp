#include <iostream>
#include <fstream>
#include <list>
#include <cmath>
#include "FileManager.h"




bool FileManager::openInputFile(const std::string& FilePath){
    inputFile.open(FilePath);
    return inputFile.is_open();
}
bool FileManager::openOutputFile(const std::string& FilePath) {
    outputFile.open(FilePath);
    return outputFile.is_open();
}
bool FileManager::readline(std::string& line){
    auto& state = getline(inputFile, line);
    return state? true:false;
}
void FileManager::writeCSV(std::list<std::pair<std::string, int>>  sortedWords, int totalWords) {
    for (auto &pair : sortedWords) {
        double percentage = round(static_cast<double>(pair.second) / totalWords * 100 * 100) / 100;
        outputFile << pair.first << "," << pair.second << "," << percentage << "%\n";
    }
}

