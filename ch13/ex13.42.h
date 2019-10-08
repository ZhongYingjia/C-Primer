#ifndef EX13_42_H
#define EX13_42_H

#include "ex13.40.h"
#include <string>
#include <map>
#include <set>
#include <fstream>
#include <memory>
#include <iostream>
class QueryResult;
class TestQuery{
    public:
        using LineNo = size_t; 
        TestQuery(std::ifstream &ifs);
        QueryResult query(const std::string &s) const;

    private:
        std::shared_ptr<StrVec> content; 
        std::map<std::string,std::shared_ptr<std::set<LineNo>>> result;

};

class QueryResult{
    friend std::ostream &print(std::ostream&, const QueryResult&);
    public:
        QueryResult(const std::string &w, std::shared_ptr<StrVec> c, 
                    std::shared_ptr<std::set<TestQuery::LineNo>> l):
                    word(w), content(c), lNo(l){ }
    private:
        std::shared_ptr<StrVec> content;
        const std::string word;
        std::shared_ptr<std::set<TestQuery::LineNo>> lNo;
};

std::ostream &print(std::ostream &, const QueryResult&);

#endif