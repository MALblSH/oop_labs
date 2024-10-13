#include <iostream>
#include <fstream>
#include <list>
#include <cmath>
#include "../include/FileWritter.h"


bool FileWritter::openOutputFile(const std::string& FilePath) {
    outputFile.open(FilePath);
    return outputFile.is_open();
}

void FileWritter::writeCSV(std::list<std::pair<std::string, int>>  sortedWords, int totalWords) {
    for (auto &pair : sortedWords) {
        double percentage = round(static_cast<double>(pair.second) / totalWords * 100 * 100) / 100;
        outputFile << pair.first << "," << pair.second << "," << percentage << "%\n";
    }
}

