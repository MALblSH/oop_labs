#include <fstream>
#include <list>

class FileReader{

private:
    std::ifstream inputFile;
public:
    bool openInputFile(const std::string& FilePath);
    bool readline(std::string& line);
};