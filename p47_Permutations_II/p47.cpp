#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        dfs(ans, nums, 0);
        return ans;
    }
    void dfs(vector<vector<int> > ans, vector<int> v, int pos) {
        if(pos==(v.size()-1)) {
            ans.push_back(v);
            /*for(vector<int>::iterator it=v.begin(); it!=v.end(); it++) printf("%d ",*it);
            printf("\n");*/
            return;
        }
        for(int k = pos; k < v.size(); k++) {
            if(pos!=k&&v[pos]==v[k]) continue;
            swap(v[pos],v[k]);
            dfs(ans,v,pos+1);;
        }
    }
};

int main () {
    vector<int> x;
    x.push_back(1);
    x.push_back(1);
    x.push_back(3);
    x.push_back(3);
    /*for(vector<int>::iterator it=x.begin(); it!=x.end(); it++)printf("%d ",*it);
    printf("\n");
    swap(x[0],x[2]);
    for(vector<int>::iterator it=x.begin(); it!=x.end(); it++)printf("%d ",*it);
    printf("\n");
    swap(x[0],x[2]);
    for(vector<int>::iterator it=x.begin(); it!=x.end(); it++)printf("%d ",*it);
    printf("\n");*/
    Solution s;
    vector<vector<int> > y = s.permuteUnique(x);
	return 0;
}