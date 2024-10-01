#include <iostream>
#include "..\include\FileManager.h"
#include "..\include\WordCounter.h"


int main(int argc, char* argv[]) {
    std::string line;
    if(argc != 3){
        std::cerr << "Error: invalid number of arguments" << std::endl;
        return 1;
    }
    FileManager fileManager;
    if(!fileManager.openInputFile(argv[1])){
        std::cerr << "Error: can't open file" << argv[1] << std::endl;
        return 1;
    }
    WordCounter wordCounter;
    while(fileManager.readline(line)){
        wordCounter.processLine(line);
    }
    if(!fileManager.openOutputFile(argv[2])){
        std::cerr << "Error: can't open file" << argv[2] << std::endl;
        return 1;
    }
    fileManager.writeCSV(wordCounter.getSortedWords(), wordCounter.getTotalWords());
    return 0;
}
