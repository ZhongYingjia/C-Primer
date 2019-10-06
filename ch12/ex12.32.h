#ifndef EX12_32_H
#define EX12_32_H

// #include <vector>
// #include <string>
#include <map>
#include <set>
#include <fstream>
#include <memory>
#include <iostream>
#include "ex12.22.h"

class QueryResult;
class TextQuery {
public:
    TextQuery(std::ifstream&);
    QueryResult query(const std::string&) const;

private:
    std::shared_ptr<StrBlob> input;
    std::map<std::string, std::shared_ptr<std::set<StrBlob::size_type>>> result;
};

class QueryResult {
public:
    friend std::ostream& print(std::ostream&, const QueryResult&);

public:
    QueryResult(const std::string& s, std::shared_ptr<std::set<StrBlob::size_type>> set,
                std::shared_ptr<StrBlob> v)
        : word(s), nos(set), input(v)
    {
    }

private:
    std::string word;
    std::shared_ptr<std::set<StrBlob::size_type>> nos;
    std::shared_ptr<StrBlob> input;
};

std::ostream& print(std::ostream&, const QueryResult&);

#endif