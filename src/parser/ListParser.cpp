#undef BOOST_SPIRIT_DEBUG
#undef BOOST_SPIRIT_DEBUG_WS

#include "base/ListDef.hpp"
#include "parser/ListParser.hpp"

#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/spirit/include/phoenix_object.hpp>
#include <boost/spirit/include/phoenix_fusion.hpp>
#include <boost/spirit/include/phoenix_stl.hpp>
#include <boost/fusion/include/adapt_struct.hpp>

#include <istream>
#include <fstream>

namespace 
{

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;
namespace phoenix = boost::phoenix;
namespace fusion = boost::fusion;


template<typename Iterator>
struct SkipperGrammar : boost::spirit::qi::grammar<Iterator>
{
  SkipperGrammar(): SkipperGrammar::base_type(ws)
  {
    using namespace boost::spirit;
    ws = ascii::space
       | qi::lexeme[ qi::char_('#') > *(qi::char_ - qi::eol) ];

    #ifdef BOOST_SPIRIT_DEBUG_WS
    BOOST_SPIRIT_DEBUG_NODE(ws);
    #endif
  }

  boost::spirit::qi::rule<Iterator> ws; 
};



template<typename Iterator, typename Skipper>
struct ListParserGrammar: qi::grammar<Iterator, Skipper>
{
  ListParserGrammar() : ListParserGrammar::base_type(start)
  {
    using qi::lit;
    using qi::eps;
    using qi::_1;
    using qi::int_;
    using qi::uint_;
    using qi::_val;
    using namespace qi::labels;
    using phoenix::construct;
    using phoenix::new_;
    using phoenix::push_back;
    using phoenix::insert;
    using phoenix::at_c;

    start = (lit('[') >> (constants [_a=construct<ConstantListPtr>(new_<ConstantList>(_1))]) >> lit(']'));

    constants %= lit("Constants:") >> lit('[') >> constant % lit(',') >> lit(']');
    constant %= +(ascii::alnum);
  }

  qi::rule<Iterator, Skipper> start;
  qi::rule<Iterator, ConstantListPtr(), Skipper> constants;
  qi::rule<Iterator, Constant(), Skipper> constant;
};

} // namespace

void
ListParser::parseFile(const std::string &inFile)
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
ListParser::parseStream(std::istream &in)
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
ListParser::parseString(const std::string &inStr)
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
