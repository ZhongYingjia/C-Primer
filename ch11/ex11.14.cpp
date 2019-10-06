#include <vector>
#include <string>
#include <utility>
#include <map>
#include <iostream>

using std::vector;
using std::string;
using std::pair;
using std::map;
class Faml
{
    public:
        using child = pair<string,string>;
        using children = vector<child>;
        using Data = map<string, children>;

        void add(string& lastName, string& firstName, string& birthday)
        {
            data[lastName].push_back({firstName,birthday});
        }

        void print(std::ostream& os){
            for(const auto& c : data){
                os << c.first << ":"<<std::endl;
                for(const auto& p : c.second){
                    os << p.first << " " << p.second <<std::endl;
                }
            }
        }
    private:
        Data data;
};

int main()
{
    Faml faml;
    std::cout <<"Please input your message:" <<std::endl;
    string l,f,b;
    while(std::cin >> l >> f >> b){
        faml.add(l,f,b);
    }

    faml.print(std::cout);
    
    
    
    return 0;
}