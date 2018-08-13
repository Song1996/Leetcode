#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        /*vector<int> t;
        t.push_back(7);
        ans.push_back(t);
        t.pop_back();
        t.push_back(2);
        t.push_back(2);
        t.push_back(3);
        ans.push_back(t);*/
        vector<int> buffer;
        dfs(ans, candidates, target, buffer, 0);
        return ans;
    }
    void dfs(vector<vector<int> >& ans, vector<int>& v, int target,vector<int> buffer, int pos) {
        int t;
        if (target < 0) return;
        else if(target == 0) {
            ans.push_back(buffer);
            return;
        }
        for (int i = pos; i < v.size(); i ++) {
            if (v[i] > target) continue;
            else if (v[i] == target) {
                buffer.push_back(v[i]);
                ans.push_back(buffer);
                buffer.pop_back();
            }else {
                int tms = 1;
                while (v[i]*tms <= target) {
                    buffer.push_back(v[i]);
                    dfs(ans, v, target-(v[i]*tms), buffer, i+1);
                    tms ++;
                }
                tms--;
                if(buffer.size()>=tms) buffer.erase(buffer.end()-tms, buffer.end());
                //else printf("error %lu %d\n",buffer.size(),tms);
            }
        }
        return;
    }
};

int main () {
    Solution s;
    vector<int> x;
    x.push_back(2);
    x.push_back(3);
    x.push_back(5);
    //x.push_back(7);
    int target = 8;
    vector<vector<int> > y =  s.combinationSum(x,target);
    for (vector<vector<int> >::iterator it = y.begin(); it != y.end(); it ++) {
        for(vector<int>::iterator itt = it->begin(); itt != it->end(); itt ++) {
            printf("%d ",*itt);
        }printf("\n");
    }
	return 0;
}