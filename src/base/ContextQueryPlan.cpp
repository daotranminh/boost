#include "base/ContextQueryPlan.hpp"


std::ostream&
ContextQueryPlan::print(std::ostream &os) const
{
  os << "  {" << std::endl;
  if ( !!constants && !constants->empty() )
    os << "  Constants:" << std::endl
       << "  [" << std::endl
       << *constants 
       << "  ]" << std::endl;

  os << "  }" << std::endl;
}
