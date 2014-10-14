#ifndef __NUMBER_PARSER_HPP__
#define __NUMBER_PARSER_HPP__

#include <istream>
#include <string>

class NumberParser
{
public:
  static void parseStream(std::istream &in);
  static void parseFile(const std::string &inFile);
  static void parseString(const std::string &inStr);
};

#endif // __NUMBER_PARSER_HPP__
