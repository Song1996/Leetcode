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
    bool isAdditiveNumber(string num) {

        //printf("%s\n",dfs(ans, S, 0, -1, -1, false)?"true":"false");
        return dfs(num, 0, -1, -1, false);
    }
    bool dfs(string& S, int pos, int x1, int x2, bool f3) {
        if(pos == S.length()) {
            return f3;
        }
        if(S[pos] == '0') {
            if(x1<0) return dfs(S, pos+1, 0, x2, false);
            if(x2<0) return dfs(S, pos+1, x1, 0, false);
            else if((x1+x2)==0) return dfs(S, pos+1, x2, 0, true);
            return false;
        }
        int t;
        bool flag = false;
        for(int i = 1; i <= S.length()-pos; i++) {
            t = atoi(S.substr(pos,i).c_str());
            if(x1<0) {if(dfs(S, pos+i, t, x2, false)) flag = true;}
            else if(x2<0) {if(dfs(S, pos+i, x1, t, false)) flag = true;}
            else if(x1+x2==t) {if(dfs(S, pos+i, x2, t, true)) flag = true;}
        }
        return flag;
    }
};

int main () {
    Solution s;
    string x = "112358"; printf("%s %s\n",x.c_str(), s.isAdditiveNumber(x)?"true":"false");
    x = "199100199"; printf("%s %s\n",x.c_str(), s.isAdditiveNumber(x)?"true":"false");
    x = "000"; printf("%s %s\n",x.c_str(), s.isAdditiveNumber(x)?"true":"false");
	return 0;
}