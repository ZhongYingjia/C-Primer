#include "ex13.42.h"
#include <sstream>

using std::string;
using std::shared_ptr;
using std::set;

TestQuery::TestQuery(std::ifstream& ifs): content(new StrVec)
{
    string text;
    while(std::getline(ifs, text)){
        content->push_back(text);
        auto n = content->size() - 1;
        std::istringstream line(text);
        string word;
        while(line >> word){
            auto &lines = result[word];
            if(!lines){
                lines.reset(new set<LineNo>);
            }
            lines->insert(n);
        }
    } 
}

QueryResult TestQuery::query(const string& sought) const 
{
    static shared_ptr<set<LineNo>> nodata(new set<LineNo>);
    auto loc = result.find(sought);
    if(loc == result.end()){
        return QueryResult(sought, content, nodata);
    }
    return QueryResult(sought, content, loc ->second);

}

std::ostream& print(std::ostream &os, const QueryResult& qr)
{
    os << qr.word <<" occurs " << qr.lNo->size() <<
    " "<< (qr.lNo->size() > 1? "times":"time") <<std::endl;
    for(auto num : *qr.lNo){
        std::cout << "\t(line " << num+1 << ") " <<*(qr.content->begin()+num) <<std::endl;
    }
    return os;


}