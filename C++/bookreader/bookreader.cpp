#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
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
std::string format(std::string word){
    std::string s = word;
    for(int x = 0; x < s.length(); x++){
        if(!(isalpha(s[x]) && islower(s[x]))){
            if(isupper(s[x])){
                s[x] = tolower(s[x]);
            }
            else{
                s = s.substr(0, x) + s.substr(x+1);
                x--;
            }
        }
    }
    return s;
}
std::pair<std::string, int> mostFreq(std::vector<std::string> words){
    std::map<std::string, int> wordmap;
    for(int x = 0; x < words.size(); x++){
        words[x] = format(words[x]);
        std::map<std::string, int>::iterator it = wordmap.find(words[x]);
        if(it != wordmap.end()){
            it->second = it->second+1;
        }
        else {
            wordmap.insert(make_pair(words[x], 1));
        }
    }
    std::map<std::string, int>::iterator i = wordmap.begin();
    std::pair<std::string, int> mostFrequent;
    mostFrequent.first = i->first;
    mostFrequent.second = i->second;
    while(i != wordmap.end()){
        if(i->second > mostFrequent.second){
            mostFrequent.first = i->first;
            mostFrequent.second=i->second;
        }
        i++;
    }
    return mostFrequent;
}
int main() {
    std::string filename;
    std::cout << "Enter in a file name (with extension): ";
    std::cin >> filename;
    std::vector<std::string> words = readFile(filename);
    std::pair<std::string, int> frequent = mostFreq(words);
     std::cout << "\"" <<frequent.first << "\"" << " is the most frequent word with a frequency of " << frequent.second << "." << std::endl;
    return 0;
}
