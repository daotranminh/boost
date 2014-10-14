#ifndef __LIST_DEF_HPP__
#define __LIST_DEF_HPP__

#include <list>
#include <string>

typedef std::string Constant;
typedef std::list<Constant> ConstantList;

struct ConstantCategory
{
  std::string name;
  ConstantList constants;

  ConstantCategory(const std::string &name);
};

typedef std::list<ConstantCategory> ConstantCategoryList;

#endif // __LIST_DEF_HPP__
