#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i = 0; i < tokens.size(); i++) {
            string& x = tokens[i];
            if(x.length()==1) {
                if(x[0]=='*') {
                    int t1 = s.top(); s.pop();
                    int t2 = s.top(); s.pop();
                    s.push(t1*t2);
                }else if(x[0]=='+') {
                    int t1 = s.top(); s.pop();
                    int t2 = s.top(); s.pop();
                    s.push(t1+t2);                    
                }else if(x[0]=='-') {
                    int t1 = s.top(); s.pop();
                    int t2 = s.top(); s.pop();
                    s.push(t2-t1);                    
                }else if(x[0]=='/') {
                    int t1 = s.top(); s.pop();
                    int t2 = s.top(); s.pop();
                    s.push(t2/t1);                    
                }else {
                    s.push(atoi(x.c_str()));
                }
            }else s.push(atoi(x.c_str()));
        }
        return s.top();
    }
};

int main() {
    vector<string> x;
    x.push_back("2"); x.push_back("1"); x.push_back("+"); x.push_back("-3"); x.push_back("*");
    Solution s;
    printf("%d\n",s.evalRPN(x));
}