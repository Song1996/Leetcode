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
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > ans;
        if(nums.size()==0) return ans;
        map<int, int> d;
        for(int i=0; i<nums.size(); i++) {
            if(d.find(nums[i])==d.end()) d[nums[i]] = 1;
            else d[nums[i]] = d[nums[i]]+1;
        }
        /*vector<int> x;
        for(map<int, int>::iterator it=d.begin(); it!=d.end(); it++) {
            x.push_back(it->first);
            //printf("%d %d\n",it->first,it->second);
        }*/
        vector<int> t;
        dfs(ans, t, d, d.begin());
        return ans;
    }
    void dfs(vector<vector<int> >& ans, vector<int> state, map<int, int>& d, map<int, int>::iterator it) {
        /*for(int i=0; i<state.size(); i++) printf("%d ",state[i]);
        printf("\n");*/
        if(it==d.end()) {
            ans.push_back(state);
            return;
        }
        int element = it->first;
        int tms = it->second;
        dfs(ans, state, d, ++it);
        for(int i = 0; i<tms; i++) {
            state.push_back(element);
            dfs(ans, state, d, it);
        }
    }
};

int main () {
    vector<int> x;
    x.push_back(1); x.push_back(1); x.push_back(2);
    Solution s;
    vector<vector<int> > y = s.subsetsWithDup(x);
    for(int i = 0; i<y.size(); i++){
        for(int j = 0; j<y[i].size(); j++){
            printf("%d ",y[i][j]);
        }printf("\n");
    }
	return 0;
}