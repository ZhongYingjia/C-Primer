#include "AndQuery.h"
#include <algorithm>

QueryResult
AndQuery::eval(const TextQuery &text) const
{
    auto left = lhs.eval(text), right = rhs.eval(text);
    auto ret_line = std::make_shared<std::set<line_no>>();
    std::set_intersection(left.begin(), left.end(), 
                        right.begin(), right.end(), 
                        std::inserter(*ret_line, ret_line->begin()));
    return QueryResult(rep(), ret_line, left.get_file());
}