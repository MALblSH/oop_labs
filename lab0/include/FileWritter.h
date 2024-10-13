#include <fstream>
#include <list>


class FileWritter{
private:
    std::ofstream outputFile;
public:
    bool openOutputFile(const std::string& FilePath);
    void writeCSV(std::list<std::pair<std::string,int>> sortedWords, int totalWords);
};