#include <iterator>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using std::vector;
using std::string;
int main()
{
    std::ifstream ifs("book.txt");
    std::istream_iterator<string> in_iter(ifs),eof;
    vector<string> vs;

    std::copy(in_iter, eof,std::back_inserter(vs));

    std::ostream_iterator<string> out_iter(std::cout, "\n");
    std::copy(vs.begin(),vs.end(),out_iter);

    // vector<string> context(in_iter,eof);

    // std::ostream_iterator<string> out_iter(std::cout, " ");

    // for(auto &i : context){
    //     *out_iter++ = i;
    // }
   

    
    
    
    return 0;
}