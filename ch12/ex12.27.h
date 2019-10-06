#ifndef EX12_27_H
#define EX12_27_H

#include <vector>
#include <string>
#include <map>
#include <set>
#include <fstream>
#include <memory>
#include <iostream>
class QueryResult;
class TestQuery{
    public:
        using LineNo = std::vector<std::string>::size_type; 
        TestQuery(std::ifstream &ifs);
        QueryResult query(const std::string &s) const;

    private:
        std::shared_ptr<std::vector<std::string>> content; 
        std::map<std::string,std::shared_ptr<std::set<LineNo>>> result;

};

class QueryResult{
    friend std::ostream &print(std::ostream&, const QueryResult&);
    public:
        QueryResult(const std::string &w, std::shared_ptr<std::vector<std::string>> c, 
                    std::shared_ptr<std::set<TestQuery::LineNo>> l):
                    word(w), content(c), lNo(l){ }
    private:
        std::shared_ptr<std::vector<std::string> > content;
        const std::string word;
        std::shared_ptr<std::set<TestQuery::LineNo>> lNo;
};

std::ostream &print(std::ostream &, const QueryResult&);

#endif