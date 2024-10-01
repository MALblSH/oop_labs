#include <fstream>
#include <list>


class FileManager{
private:
    std::ifstream inputFile;
    std::ofstream outputFile;
public:
    bool openInputFile(const std::string& FilePath);
    bool openOutputFile(const std::string& FilePath);
    bool readline(std::string& line);
    void writeCSV(std::list<std::pair<std::string,int>> sortedWords, int totalWords);
};