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
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<int> mem(k+1); mem[0] = 0;
        vector<vector<int> > ans;
        dfs(ans, mem, 1, n);
        return ans;
    }
    void dfs(vector<vector<int> >& ans, vector<int>& mem, int pos, int res) {
        if(pos<mem.size()) {
            for(int i = mem[pos-1]+1; i < 10; i++) {
                if(i<=res) { 
                    mem[pos] = i;
                    dfs(ans, mem, pos+1, res-i);
                }
            }
        }else if(res==0) {
            vector<int> t(begin(mem)+1, end(mem));
            ans.push_back(t);
        }
    }
};

int main () {
    Solution s;
    vector<vector<int> > y = s.combinationSum3(3, 9);
    for(int i = 0; i < y.size(); i++) {
        for(int j = 0; j < y[i].size(); j++) {
            printf("%d ",y[i][j]);
        }printf("\n");
    }
	return 0;
}