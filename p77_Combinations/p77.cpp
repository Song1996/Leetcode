#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <string>
#include <assert.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ans;
        vector<int> mem(k,0);
        dfs(ans, mem, 0, 1, n, k);
        return ans;
    }
    void dfs(vector<vector<int> >&ans, vector<int>& mem, int p, int ps, int n, int k) {
        for(int i = ps; n-i >= k-p-1; i++) {
            mem[p] = i;
            if(p+1==k) ans.push_back(mem);
            else dfs(ans, mem, p+1, i+1, n, k);
        }
        return;
    }
};

int main () {
    Solution s;
    vector<vector<int> > y = s.combine(6,3);
    for(int i = 0; i < y.size(); i++) {
        for(int j = 0; j < y[i].size(); j++){
            printf("%d ",y[i][j]);
        }printf("\n");
    }
	return 0;
}