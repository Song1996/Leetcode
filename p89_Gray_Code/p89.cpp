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
    vector<int> grayCode(int n) {
        vector<int> ans;
        dfs(ans, 0, n, false);
        return ans;
    }
    void dfs(vector<int>& ans,int state, int n, bool flag) {
        if(n==0) {
            ans.push_back(state);
            return;
        }
        if(flag) {
            dfs(ans, state^(1<<(n-1)), n-1, false);
            dfs(ans, state, n-1, true);
        }else {
            dfs(ans, state, n-1, false);
            dfs(ans, state^(1<<(n-1)), n-1, true);
        }
    }
};

int main () {
    int x = 2;
    Solution s;
    vector<int> y = s.grayCode(x);
    for(int i = 0; i < y.size(); i++){
        printf("%d ",y[i]);
    }printf("\n");
	return 0;
}