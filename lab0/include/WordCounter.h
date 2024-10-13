#include <iostream>
#include <list>
#include <map>


class WordCounter{
private:
    std::map<std::string,int> wordCounter;
    int totalWords{0};
public:
    static std::list<std::string> splitWords(std::string& text);
    void addWord(std::list<std::string>& words);
    void processLine(std::string& line);
    std::list<std::pair<std::string,int>> getSortedWords();
    int getTotalWords();
};
