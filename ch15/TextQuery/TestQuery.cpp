#include "TextQuery.h"
#include "QueryResult.h"
#include <sstream>
#include <algorithm>
#include <iterator>
using std::istringstream;

using std::ifstream;
using std::vector;
using std::string;
using std::set;
using std::shared_ptr;

TextQuery::TextQuery(ifstream& is): file(new vector<string>)
{
    line_no ln{0};
    for(string line; std::getline(is, line); ++ln){
        file->push_back(line);
        istringstream line_stream(line);
        for(string text, word; line_stream >> text; word.clear()){
            std::remove_copy_if(text.cbegin(), text.cend(), std::back_inserter(word), ispunct);
            auto &nos = wm[word];
            if(!nos) nos.reset(new set<line_no>);
            nos->insert(ln);
        }
    }
    //std::cout << file->size();
}

QueryResult
TextQuery::query(const string &sought) const{
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(sought);
    if(loc == wm.end()){
        return QueryResult(sought, nodata, file);
    } else {
        return QueryResult(sought, loc->second, file);
    }
}
