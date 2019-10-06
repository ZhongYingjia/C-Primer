#include <vector>
#include <stack>
#include <iostream>
using namespace std;
int main()
{   
    string input;
    getline(cin,input);
    stack<int> left;
    int count = 0;
    for(auto i : input)
    {
        if (i == '('){
            left.push(i);
        }else if(i == ')'){
            if(left.empty()){
                count += 1;
            }else{
                left.pop();
            }
        }
    }

    count += left.size();

    cout << count <<endl;


    return 0;

}