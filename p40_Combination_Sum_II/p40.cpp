#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        ans.clear();
        vector<int> buffer;
        buffer.clear();
        sort(candidates.begin(), candidates.end());
        /*for(vector<int>::iterator it = candidates.begin(); it != candidates.end(); it ++) printf("%d ",*it);
        printf("\n");*/
        dfs(candidates, ans, target, buffer, 0);
        return ans;
    }
    void dfs(vector<int>& v, vector<vector<int> >& ans, int target, vector<int>& buffer, int pos) {
        if (target<0) return;
        else if (target == 0) {
            ans.push_back(buffer);
            return;
        }
        int i = pos;
        while(i < v.size()){
            if(v[i]>target) i++;
            else {
                int t = 0;
                while((i+t)<v.size()&&v[i+t]==v[i]) t++;
                for(int j = 1; j <= t; j++){
                    buffer.push_back(v[i]);
                    dfs(v, ans, target-(v[i]*j), buffer, i+t);
                }
                buffer.erase(buffer.end()-t,buffer.end());
                i += t;
            }
        }
    }
};

int main () {
    vector<int> x;
    /*
    x.push_back(10);
    x.push_back(1);
    x.push_back(2);
    x.push_back(7);
    x.push_back(6);
    x.push_back(1);
    x.push_back(5);*/
    x.push_back(2);
    x.push_back(1);
    x.push_back(3);
    x.push_back(1);
    x.push_back(4);
    x.push_back(4);
    int target = 10;
    Solution s;
    vector<vector<int> > y = s.combinationSum2(x, target);
    for(vector<vector<int> >::iterator it = y.begin(); it != y.end(); it ++) {
        for (vector<int>::iterator itt = it->begin(); itt != it->end(); itt ++)
            printf("%d ",*itt);
        printf("\n");
    }
	return 0;
}