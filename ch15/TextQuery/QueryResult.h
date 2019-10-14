#ifndef QueryResult_H
#define QueryResult_H

#include "TextQuery.h"

class QueryResult{
    friend std::ostream& operator<<(std::ostream&, const QueryResult&);
public:
    QueryResult(std::string s, 
                std::shared_ptr<std::set<TextQuery::line_no>> p,
                std::shared_ptr<std::vector<std::string>> f):
                sought(s), lines(p), file(f) { }
    
    std::set<TextQuery::line_no>::iterator begin() { return lines->begin(); }
    std::set<TextQuery::line_no>::iterator end() { return lines->end(); }
    std::shared_ptr<std::vector<std::string>> get_file() const { return file; }

private:
    std::string sought;
    std::shared_ptr<std::set<TextQuery::line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
    
};
std::ostream &operator<<(std::ostream &, const QueryResult &);


#endif