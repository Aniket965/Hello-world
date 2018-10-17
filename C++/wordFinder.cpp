#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
std::vector<std::string> readFile(std::string bookdir){
    std::ifstream file;
    file.open(bookdir);
    if(!file){
        std::cerr << "file does not exist" << std::endl;
        exit(1);
    }
    std::string word;
    std::vector<std::string> temp;
    while(file>>word){
        temp.push_back(word);
    }
    file.close();
    return temp;
}

bool findInVector(std::vector<std::string> wordList, std::string find){
    int count = std::count(wordList.begin(), wordList.end(), find);
    return (count > 0);
}

int main() {
    std::string filename, wordToFind;
    std::cout << "Enter in a file name (with extension): ";
    std::cin >> filename;
    std::vector<std::string> words = readFile(filename);
    std::cout << "Enter in a word/name to find: ";
    std::cin >> wordToFind;
    bool existsInFile = findInVector(words, wordToFind);
    if(existsInFile)
        std::cout << wordToFind << " is found in the file." << std::endl;
    else
        std::cout << wordToFind << " is not found in the file." << std::endl;
    return 0;
}
