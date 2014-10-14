#ifndef __LIST_DEF_HPP__
#define __LIST_DEF_HPP__

#include <list>
#include <string>

#include <boost/shared_ptr.hpp>

typedef std::string Constant;
typedef std::list<Constant> ConstantList;
typedef boost::shared_ptr<ConstantList> ConstantListPtr;

struct ConstantCategory
{
  std::string name;
  ConstantList constants;

  ConstantCategory(const std::string &name);
};

typedef std::list<ConstantCategory> ConstantCategoryList;
typedef boost::shared_ptr<ConstantCategoryList> ConstantCategoryListPtr;

#endif // __LIST_DEF_HPP__
