#include <iostream>
#include <vector>
#include <algorithm>
int main() {
  std::vector<std::string> words {"These", "Words", "Will", "Be", "Sorted", "After", "Size"};
  std::sort(words.begin(), words.end(), [](auto a, auto b) { return a.size() < b.size(); });
  for (auto word : words) std::cout << word << ", ";
  return 0;
}