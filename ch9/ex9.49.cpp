#include <string>
#include <fstream>
#include <iostream>

using std::string;


int main()
{
	std::ifstream ifs("letter.txt");
    if(!ifs) return -1;
    string legal("aceimnorsuvwxz");
    string longestWord;
    string word;
    while(ifs >> word){
        if((word.find_first_not_of(legal) == string::npos) && word.size() > longestWord.size()){
            longestWord = word;
        }
    }

    std::cout << longestWord << "\n";

    return 0;
    
}