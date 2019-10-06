#include <iterator>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

#include<algorithm>

using std::vector;
using std::string;
int main()
{
    std::istream_iterator<int> in_iter(std::cin),eof;
    vector<int> vi;
    std::copy(in_iter, eof, std::back_inserter(vi));
    std::sort(vi.begin(),vi.end());
    auto unique_end = std::unique(vi.begin(),vi.end());
    vi.erase(unique_end,vi.end());
    std::ostream_iterator<int> out_iter(std::cout," ");
    std::copy(vi.begin(),vi.end(),out_iter);
    
    
    return 0;
}