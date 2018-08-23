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
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<vector<int> > G(numCourses);
        for(int i = 0; i < prerequisites.size(); i++) {
            G[prerequisites[i].first].push_back(prerequisites[i].second);
        }
        vector<int> vis(numCourses);
        for(int i = 0; i < numCourses; i ++) {
            if(vis[i]!=2 && !dfs(G,vis,i)) {
                //printf("%d\n",i);
                return false;
            }
        }
        return true;
    }
    bool dfs(vector<vector<int> >& G, vector<int>& vis, int node ) {
        //printf("%d\n",node);
        vis[node] = 1;
        for(int i = 0; i < G[node].size(); i++) {
            if(vis[G[node][i]]==1) return false;
            else if(vis[G[node][i]]==2) continue;
            else if(!dfs(G,vis,G[node][i])) return false;
        }
        vis[node] = 2;
        return true;
    }
};

int main () {
    vector<pair<int, int> > prerequisites;
    pair<int, int> t;
    //t.first = 1; t.second = 0; prerequisites.push_back(t);
    t.first = 0; t.second = 1; prerequisites.push_back(t);
    Solution s;
    printf("%s\n",s.canFinish(2,prerequisites)?"true":"false");
	return 0;
}