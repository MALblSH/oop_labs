#include <iostream>
#include <list>


#include "WordCounter.h"


std::list<std::string> WordCounter::splitWords(std::string &text) {
    std::list<std::string> words;
    std::string temp;
    for(auto& ch:text){
        if(isalnum(ch)){
            temp += tolower(ch);
        } else if(isspace(ch)){
            if(temp.length()>0){
                words.push_back(temp);
                temp = "";
            }
        }
    }
    if(temp.length()>0){
        words.push_back(temp);
    }
    return words;
}

void WordCounter::addWord(std::list<std::string>& words) {
    for(auto& word : words){
        wordCounter[word]++;
        totalWords++;
    }
}
void WordCounter::processLine(std::string &line) {
    std::list<std::string> words = WordCounter::splitWords(line);
    addWord(words);
}
std::list<std::pair<std::string,int>> WordCounter::getSortedWords() {
    std::list<std::pair<std::string,int>> sortedWords(wordCounter.begin(),wordCounter.end());
    sortedWords.sort([](const std::pair<std::string,int> &a, const std::pair<std::string,int> &b){
        return a.second<b.second;
    });

    
    return sortedWords;
}
int WordCounter::getTotalWords() {
    return totalWords;
}