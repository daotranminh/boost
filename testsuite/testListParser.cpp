#include "parser/ListParser.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE "testListParser"
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <fstream>

void 
testParser (const std::string& filename)
{
  std::ifstream inp;
  inp.open(filename.c_str());

  if(!inp.is_open())
  {
    std::cout << "File " << filename << " cannot be opened!" << std::endl;
  }
 
  inp.seekg(0, std::ios::end);
  int length = inp.tellg();
  inp.seekg(0, std::ios::beg);
  

  std::string buffer;
  buffer.resize(length);
  inp.read(&buffer[0], length);
  inp.close(); 

  std::cerr << "Following query plan will be parsed:" << std::endl
	    << buffer << std::endl;
  
  ListParser::parseString(buffer);
}



BOOST_AUTO_TEST_CASE ( testListParser )
{
  const char* ex = getenv("EXAMPLESDIR");
  assert (ex != 0);

  std::string fileNames [] = {"parsingExample1.txt"};
  int index = 1;
  for(int i = 0; i < index; i++)
  {
    std::string filename(ex);
    filename = filename + "/" + fileNames[i];

    testParser(filename);
  }

}
