#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int start = -1;
        int ans = myeval(tokens, tokens.size() -1, start);
        //printf("%d\n",start);
        return ans;
    }

    int myeval(vector<string>& tokens, int end, int& start) {
        //printf("%d %s\n",end,tokens[end].c_str());
        string op = tokens[end];
        if(op.length()==1)
        {   if(op[0]=='*') {
                int right = myeval(tokens, end-1, start);
                return myeval(tokens, start, start)*right;                   
            }else if(op[0]=='+') {
                int right = myeval(tokens, end-1, start);
                return myeval(tokens, start, start)+right;                   
            }else if(op[0]=='-') {
                int right = myeval(tokens, end-1, start);
                return myeval(tokens, start, start)-right;            
            }else if(op[0]=='/') {
                int right = myeval(tokens, end-1, start);
                return myeval(tokens, start, start)/right;
            } else {
                start = end-1;
                return atoi(op.c_str());
            }
        } else {
            start = end-1;
            return atoi(op.c_str());
        }
        return 0;
    }
};

int main() {
    vector<string> x;
    x.push_back("2"); x.push_back("1"); x.push_back("+"); x.push_back("-3"); x.push_back("*");
    Solution s;
    printf("%d\n",s.evalRPN(x));
}