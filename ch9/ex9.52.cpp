#include <vector>
#include <stack>
#include <iostream>
using namespace std;
int main()
{   
    auto& expr = "This is (Mooophy(awesome)((((wooooooooo))))) and (ocxs) over";
    unsigned seen = 0;
    char repl = '#';

    stack<char> stk;
    for(auto c : expr){
        stk.push(c);
        if(c == '(') ++seen;
        else if(seen && c == ')'){
            while( stk.top() != '('){
                stk.pop();
            }
            stk.pop();
            --seen;
            stk.push(repl);
        }
    }
    string output;
    for(;!stk.empty();stk.pop()){
        output.insert(output.begin(),stk.top());
    }
    cout << output <<endl;



    return 0;

}