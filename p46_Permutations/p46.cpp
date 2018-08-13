
#include <memory>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > ans;
        dfs(ans, nums, 0);
        return ans;
    }
    void dfs(vector<vector<int> >& ans, vector<int>& v, int pos) {
        if(pos==v.size()){
            vector<int> temp(v.begin(), v.end());
            ans.push_back(temp);
            return;
        }
        int t;
        for(int i = pos; i < v.size(); i++) {
            t = v[i];
            v[i] = v[pos];
            v[pos] = t;
            dfs(ans, v, pos+1);
            t = v[i];
            v[i] = v[pos];
            v[pos] = t;            
        }
    }
};

int main () {
    vector<int> x;
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    Solution s;
    vector<vector<int> > y = s.permute(x);
	return 0;
}
