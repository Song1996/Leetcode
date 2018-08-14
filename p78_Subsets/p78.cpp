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
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> s;
        dfs(ans, nums, 0, s);
        return ans;
    }
    void dfs(vector<vector<int> >& ans, vector<int>& v, int k, vector<int> s) {
        if(k==v.size()){
            ans.push_back(s);
            return;
        }
        dfs(ans,v,k+1,s);
        s.push_back(v[k]);
        dfs(ans,v,k+1,s);
        return;
    }
};

int main () {
    vector<int> x;
    for(int i=1; i<=3; i++) x.push_back(i);
    Solution s;
    vector<vector<int> > y = s.subsets(x);
    for(int i = 0; i < y.size(); i++) {
        for(int j = 0; j<y[i].size(); j++){
            printf("%d ",y[i][j]);
        }printf("\n");
    }
	return 0;
}