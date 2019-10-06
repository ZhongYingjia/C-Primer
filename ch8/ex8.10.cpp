#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>


int main(){
    std::ifstream ifs("add_item");
    if(!ifs){
        std::cerr << "No data?" << std::endl;
    }
    std::vector<std::string> vec;
    std::string buf;
    while(std::getline(ifs, buf)){
        vec.push_back(buf);
    }
    
    for(auto v :vec){
        std::stringstream sstrm(v);
        std::string word;
        while(sstrm >> word) std::cout << word <<std::endl;

    }
    

    

    
    system("pause");
    return 0;
}