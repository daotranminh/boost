#ifndef __LIST_PARSER_HPP__
#define __LIST_PARSER_HPP__

#include "base/ListDef.hpp"

#include <istream>
#include <string>

class ListParser
{
public:
  static void parseStream(std::istream &in);
  static void parseFile(const std::string &inFile);
  static void parseString(const std::string &inStr);
};

#endif // __LIST_PARSER_HPP__
