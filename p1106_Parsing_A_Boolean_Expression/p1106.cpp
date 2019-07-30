#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    
    bool parseBoolExpr(string expression) {
        if(expression[0] == 't') return true;
        if(expression[0] == 'f') return false;
        stack<int> mem;
        int p = 0;
        while( p < expression.length() ) {
            if(expression[p] == '(') mem.push(p);
            else if(expression[p] == ')') {
                bool result = false;
                if(expression[mem.top() - 1] == '!') {
                    result = expression[mem.top() + 1] == 'f';
                } else if (expression[mem.top() - 1] == '|') {
                    for(int i = mem.top(); i < p; i++) {
                        if(expression[i] == 't') result = true;
                    }
                } else {
                    result = true;
                    for(int i = mem.top(); i < p; i++) {
                        if(expression[i] == 'f') result = false;
                    }
                }
                expression = expression.substr(0,mem.top()-1) + string( result?"t":"f") + expression.substr(p+1);
                p = mem.top()-1;
                mem.pop();
                //printf("%s %d\n",expression.c_str(),p);
            }
            p++;
        }
        return expression[0]=='t';
    }
};