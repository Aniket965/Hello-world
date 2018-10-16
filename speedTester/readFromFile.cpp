#include <iostream>
#include <chrono>
#include <fstream>

int main(int argc, char *argv[]){
  std::ifstream file;
  file.open("words_alpha.txt");
  if(!file)
    exit(1);
  std::string word = argv[1];
   auto start = std::chrono::high_resolution_clock::now();
  while(!file.eof()){
    std::string temp;
    file >> temp;
    if(word == temp){
      //std::cout << word << " was found!" << std::endl;
      break;
    }
  }
   auto end = std::chrono::high_resolution_clock::now();
 std::chrono::duration<double> diff = end-start;
 //std::cout << diff.count() << " elapsed" << std::endl;
 file.close();

 std::fstream outputter;
 outputter.open("./logs/cpplog.txt", std::fstream::out|std::fstream::app);
 outputter << diff.count() << std::endl;
 outputter.close();
}
