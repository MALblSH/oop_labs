#include <iostream>
#include "../include/FileWritter.h"
#include "../include/FileReader.h"
#include "../include/WordCounter.h"


int main(int argc, char* argv[]) {
    std::string line;
    if(argc != 3){
        std::cerr << "Error: invalid number of arguments" << std::endl;
        return 1;
    }
    FileReader fileReader;
    FileWritter fileWritter;
    if(!fileReader.openInputFile(argv[1])){
        std::cerr << "Error: can't open file" << argv[1] << std::endl;
        return 1;
    }
    WordCounter wordCounter;
    while(fileReader.readline(line)){
        wordCounter.processLine(line);
    }
    if(!fileWritter.openOutputFile(argv[2])){
        std::cerr << "Error: can't open file" << argv[2] << std::endl;
        return 1;
    }
    fileWritter.writeCSV(wordCounter.getSortedWords(), wordCounter.getTotalWords());
    return 0;
}
