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
    int scoreOfParentheses(string S) {
        if(S=="")return 0;
        //printf("%s\n",S.c_str());
        int n = 1;
        for(int i = 1; i < S.length(); i++) {
            if(S[i]=='(') n++;
            else n--;
            if(n==0&&i==1) return 1+scoreOfParentheses(S.substr(2));
            else if(n==0&&i>1) return 2*scoreOfParentheses(S.substr(1,i-1))+scoreOfParentheses(S.substr(i+1,S.length()-i-1));
        }
        return -1;
    }
};

int main() {
    Solution s;
    printf("%d\n",s.scoreOfParentheses("(())()"));
    return 0;
}