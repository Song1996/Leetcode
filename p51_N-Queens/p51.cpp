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
    vector<vector<string> > solveNQueens(int n) {
        vector<int> mem(n);
        for(int i = 0; i < n; i++) mem[i] = i;
        vector<vector<string> > ans;
        dfs(ans, mem, 0);
        return ans;
    }
    void dfs(vector<vector<string> >& ans, vector<int>& mem, int d) {
        if(d==mem.size()) {
            vector<string> t(mem.size());
            for(int i = 0; i < mem.size(); i++) {
                string tt(mem.size(),'.');
                tt[mem[i]] = 'Q';
                t[i] = tt;
            }
            ans.push_back(t);
            return;
        }
        for(int i = d; i < mem.size(); i++) {
            bool flag = true;
            for(int j = 0; j < d; j++) {
                if(abs(mem[j]-mem[i]) == d-j) {
                    flag = false; break;
                }
            }
            if(flag) {
                swap(mem[i],mem[d]);
                dfs(ans, mem, d+1);
                swap(mem[i],mem[d]);
            }
        }
    }
};

int main () {
    Solution s;
    vector<vector<string> > y = s.solveNQueens(4);
    for(int i = 0; i < y.size(); i++) {
        for(int j = 0; j < y[i].size(); j++){
            printf("%s\n",y[i][j].c_str());
        }printf("\n");
    }
	return 0;
}