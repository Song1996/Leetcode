#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <assert.h>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> num_s;
        stack<char> op_s;
        int pos = 0;
        while(pos!=s.length()) {
            if(s[pos]==' ') pos++;
            else if(s[pos]=='-' || s[pos]=='+' 
                    || s[pos]=='*' || s[pos]=='/') op_s.push(s[pos++]);
            else if(s[pos]<='9'&&s[pos]>='0') {
                int l = 1;
                while(pos+l<s.length() && s[pos+l]<='9'&&s[pos+l]>='0') l++;
                int x = atoi(s.substr(pos,l).c_str());
                if(!op_s.empty() && op_s.top()=='*') {x *= num_s.top(); num_s.pop(); op_s.pop();}
                if(!op_s.empty() && op_s.top()=='/') {x = num_s.top()/x; num_s.pop(); op_s.pop();}
                num_s.push(x);
                pos += l;
            }else {
                printf("error\n");
                return -1;
            }
        }
        int ans = 0;
        while(!op_s.empty()) {
            char top = op_s.top(); op_s.pop();
            if(top=='+') {
                ans += num_s.top(); num_s.pop();
            } else if(top=='-') {
                ans -= num_s.top(); num_s.pop();
            } else {printf("error2\n"); return -1;}
        }
        if(!num_s.empty()) ans += num_s.top();
        return ans;
    }
};

int main () {
    Solution s;
    string x = "3+2*2"; printf("%s = %d\n",x.c_str(),s.calculate(x));
    x = " 3/2 "; printf("%s = %d\n",x.c_str(),s.calculate(x));
    x = " 3+5 / 2 "; printf("%s = %d\n",x.c_str(),s.calculate(x));
	return 0;
}