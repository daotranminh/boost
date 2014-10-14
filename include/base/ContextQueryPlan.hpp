#ifndef __CONTEXT_QUERY_PLAN_HPP__
#define __CONTEXT_QUERY_PLAN_HPP__

#include "base/ListDef.hpp"
#include "utilities/PrintHelpers.h"

struct ContextQueryPlan : private ostream_printable<ContextQueryPlan>
{
  ContextQueryPlan()
  { }

  ContextQueryPlan(ConstantListPtr constants)
    : constants(constants)
  { }

  std::ostream& print(std::ostream &os) const;

  ConstantListPtr constants;
};

#endif // __CONTEXT_QUERY_PLAN_HPP__
