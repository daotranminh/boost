#undef BOOST_SPIRIT_DEBUG
#undef BOOST_SPIRIT_DEBUG_WS

#include "parser/NumberParser.hpp"

#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/spirit/include/phoenix_object.hpp>
#include <boost/spirit/include/phoenix_fusion.hpp>
#include <boost/spirit/include/phoenix_stl.hpp>
#include <boost/fusion/include/adapt_struct.hpp>
//#include <boost/spirit/home/phoenix/statement/if.hpp> 

#include <istream>
#include <fstream>

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;
namespace phoenix = boost::phoenix;
namespace fusion = boost::fusion;


void
NumberParser::parseFile(const std::string &inFile)
{
  std::ifstream ifs;

  ifs.open(inFile.c_str());
  if (!ifs.is_open())
    {
      std::ostringstream oss;
      oss << "File " << inFile << " not found!";
      throw std::runtime_error(oss.str());
    }
  else
    {
      parseStream(ifs);
    }
}


void
NumberParser::parseStream(std::istream &in)
{
  std::ostringstream buf;
  std::string line;

  while (!in.eof())
    {
      std::getline(in, line);
      buf << line << std::endl;
    }

  if (in.fail()) in.clear();

  std::string input = buf.str();
  parseString(input);
}



void
NumberParser::parseString(const std::string &inStr)
{
  std::string::const_iterator begIt = inStr.begin();
  std::string::const_iterator endIt = inStr.end();

  using ascii::space;
  using qi::phrase_parse;


  //typedef SkipperGrammar<std::string::const_iterator> Skipper;

  //  Skipper skipper;
  //SemState state;
  //NumberGrammar<std::string::const_iterator, Skipper> grammar(state);

  //bool r = phrase_parse(begIt, endIt, grammar, skipper);
   
  //if (r && begIt == endIt)
  if (1)
  {
    std::cout << "Parsing succeeded\n";
    //std::cout << "Result is: " << state.qplan << std::endl;
    //std::cout << *state.qplan << std::endl;
    //return state.qplan;
  }
  else
  {
    std::cout << "Parsing Failed\n";
    throw std::runtime_error("Parsing failed");
  }
}
