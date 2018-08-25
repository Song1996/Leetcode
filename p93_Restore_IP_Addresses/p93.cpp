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
    vector<string> restoreIpAddresses(string s) {
        vector<vector<string> > ans;
        vector<string> mem(4);
        vector<string> fans;
        string t;
        if(s.length()<4) return fans;
        dfs(ans, mem, s, 0);
        for(int i = 0; i < ans.size(); i++) {
            if(ans[i].size()!=4) assert(0);
            t = ans[i][0];
            for(int j = 1; j < 4; j++) t += ("."+ans[i][j]);
            fans.push_back(t);
        }
        return fans;
    }
    void dfs(vector<vector<string> >& ans, vector<string>& mem, string s, int d) {
        if(d==3) {
            if(s[0] == '0'){
                if(s.length()==1){
                    mem[d] = s;
                    ans.push_back(mem);
                }
            } else if(s.length()<4 && atoi(s.c_str()) < 256 ) {
                mem[d] = s;
                ans.push_back(mem);
            }
            return;
        }
        if(s[0]=='0') {
            if(s.length()>1) {
                mem[d] = s.substr(0,1);
                dfs(ans, mem, s.substr(1, s.length()-1), d+1);
            }
        } else {
            for(int i = 1; i < 4; i++) {
                if(s.length()<=i || atoi(s.substr(0,i).c_str())>255 ) continue;
                mem[d] = s.substr(0,i);
                dfs(ans, mem, s.substr(i,s.length()-i), d+1);
            }
        }
    }
};

int main () {
    string x = "255255255255";
    Solution s;
    vector<string> y = s.restoreIpAddresses(x);
    for(int i = 0; i < y.size(); i++) {
        printf("%s\n",y[i].c_str());
    }
	return 0;
}