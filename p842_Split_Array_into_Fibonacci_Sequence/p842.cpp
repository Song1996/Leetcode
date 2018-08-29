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
    vector<int> splitIntoFibonacci(string S) {
        vector<int> ans;
        dfs(ans, S, 0, -1, -1, false);
        return ans;
    }
    bool dfs(vector<int>& ans, string& S, int pos, int x1, int x2, bool f3) {
        if(pos == S.length()) return f3;
        if(S[pos] == '0') {
            ans.push_back(0);
            if(x1<0 && dfs(ans, S, pos+1, 0, x2, false)) return true;
            if(x2<0 && dfs(ans, S, pos+1, x1, 0, false)) return true;
            if((x1+x2)==0 && dfs(ans, S, pos+1, x2, 0, true)) return true;
            ans.pop_back();
            return false;
        }
        unsigned long long t;
        //int t;
        for(int i = 1; i <= S.length()-pos; i++) {
            t = atoi(S.substr(pos,i).c_str());
            if(t>INT_MAX) break;
            ans.push_back(t);
            if(x1<0 && dfs(ans, S, pos+i, t, x2, false)) return true;
            if(x2<0 && dfs(ans, S, pos+i, x1, t, false)) return true;
            if((x1+x2)==t && dfs(ans, S, pos+i, x2, t, true)) return true;
            ans.pop_back();
        }
        return false;
    }
};

int main () {
    Solution s;
    string x = "123456579"; printf("%s\n",x.c_str());
    vector<int> y = s.splitIntoFibonacci(x);
    for(int i = 0; i < y.size(); i++) printf("%d ",y[i]); printf("\n");
    x = "11235813"; printf("%s\n",x.c_str());
    y = s.splitIntoFibonacci(x);
    for(int i = 0; i < y.size(); i++) printf("%d ",y[i]); printf("\n");
    x = "112358130"; printf("%s\n",x.c_str());
    y = s.splitIntoFibonacci(x);
    for(int i = 0; i < y.size(); i++) printf("%d ",y[i]); printf("\n");
    x = "0123"; printf("%s\n",x.c_str());
    y = s.splitIntoFibonacci(x);
    for(int i = 0; i < y.size(); i++) printf("%d ",y[i]); printf("\n");
    x = "214748364721474836422147483641"; printf("%s\n",x.c_str());
    y = s.splitIntoFibonacci(x);
    for(int i = 0; i < y.size(); i++) printf("%d ",y[i]); printf("\n");
	return 0;
}