#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <assert.h>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<vector<int> > G(numCourses);
        for(int i = 0; i < prerequisites.size(); i++) {
            G[prerequisites[i].first].push_back(prerequisites[i].second);
        }
        vector<int> vis(numCourses);
        vector<int> ans;
        for(int i = 0; i < numCourses; i++) {
            if(vis[i]==0 && !dfs(G,vis,i,ans)){
                ans.clear();
                return ans;
            }
        }
        return ans;
    }
    bool dfs(vector<vector<int> >& G, vector<int>& vis, int node, vector<int>& ans) {
        vis[node] = 1;
        for(int i = 0; i < G[node].size(); i++) {
            if(vis[G[node][i]]==1) return false;
            if(vis[G[node][i]]==0 && !dfs(G,vis,G[node][i],ans)) return false; 
        }
        vis[node] = 2;
        ans.push_back(node);
        return true;
    }
};

int main () {
    vector<pair<int, int> > x;
    pair<int, int> t;
    t.first = 1; t.second = 0;
    x.push_back(t);
    t.first = 2; t.second = 0;
    x.push_back(t);
    t.first = 3; t.second = 1;
    x.push_back(t);
    t.first = 3; t.second = 2;
    x.push_back(t);
    Solution s;
    vector<int> y = s.findOrder(4, x);
    for(int i = 0; i < y.size(); i++) printf("%d ",y[i]); printf("\n");
	return 0;
}