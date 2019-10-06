#ifndef EX12_33_H
#define EX12_33_H

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
    using ResultIter = std::set<StrBlob::size_type>::iterator;

public:
    QueryResult(const std::string& s, std::shared_ptr<std::set<StrBlob::size_type>> set,
                std::shared_ptr<StrBlob> v)
        : word(s), nos(set), input(v)
    { }
    ResultIter begin() const { return nos->begin(); }
    ResultIter end() const { return nos->end(); }
    shared_ptr<StrBlob> get_file() const { return input; }

private:
    std::string word;
    std::shared_ptr<std::set<StrBlob::size_type>> nos;
    std::shared_ptr<StrBlob> input;
};

std::ostream& print(std::ostream&, const QueryResult&);

#endif