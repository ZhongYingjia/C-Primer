#include "OrQuery.h"

QueryResult
OrQuery::eval(const TextQuery &text) const
{
    auto right = rhs.eval(text), left = lhs.eval(text);
    auto ret_line = std::make_shared<std::set<line_no>>(left.begin(), left.end());
    ret_line->insert(right.begin(),right.end());
    return QueryResult(rep(), ret_line, left.get_file());
}