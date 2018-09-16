#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <cassert>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> S;
        for(int i = 0; i < s.length(); i++) {
            if(s[i]=='(') S.push(i);
            else if(!S.empty() && s[S.top()]=='(') S.pop();
            else S.push(i);
        }
        if(S.empty()) return s.length();
        int ans = 0;
        int b = s.length();
        while(!S.empty()) {
            ans = max(ans, b-S.top()-1);
            b = S.top();
            S.pop();
        }
        ans = max(ans, b-0);
        return ans;
    }
};

int main() {
    Solution s;
    string x = "(()"; printf("%d\n",s.longestValidParentheses(x));
    x = ")()())"; printf("%d\n",s.longestValidParentheses(x));
    return 0;
}