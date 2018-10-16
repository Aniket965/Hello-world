/*
 * string_function.h
 *
 *  Created on: Apr 20, 2018
 *      Author: hosamelsafty
 */

#ifndef STRING_FUNCTION_H_
#define STRING_FUNCTION_H_

// trim from start
  std::string &ltrim(std::string &s) ;

// trim from end
  std::string &rtrim(std::string &s) ;
  void removeSpaces(std::string &str);
// trim from both ends
  std::string &trim(std::string &s) ;
  size_t split(const std::string &txt, std::vector<std::string> &strs, char ch) ;
  void replaceAll(std::string& str, const std::string& from, const std::string& to) ;
  bool replace(std::string& str, const std::string& from, const std::string& to);



#endif /* STRING_FUNCTION_H_ */
