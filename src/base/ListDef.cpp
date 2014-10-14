#include <iostream>

#include "base/ListDef.hpp"

ConstantCategory::ConstantCategory(const std::string &name)
  : name(name)
{ }


std::ostream&
operator<<(std::ostream &os, const ConstantList &cl)
{
  ConstantList::const_iterator it = cl.begin();
  os << *it;

  for (; it != cl.end(); ++it)
    {
      os << "," << *it;
    }
}
