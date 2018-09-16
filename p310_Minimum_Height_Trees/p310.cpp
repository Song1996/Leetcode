#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <cassert>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<vector<int> > G;
    vector<bool> vis;
    vector<int> H;
    vector<int> H2;
    vector<int> findMinHeightTrees(int n, vector<pair<int, int> >& E) {
        vector<int> ans;
        //for(int i = 0; i < E.size(); i++) printf("%d %d; ",E[i].first,E[i].second); printf("\n");
        G.clear(); G.resize(n);
        for(int i = 0; i < E.size(); i++) {
            G[E[i].first].push_back(E[i].second);
            G[E[i].second].push_back(E[i].first);
        }
        vis.clear(); vis.resize(n,false);
        H.clear(); H.resize(n,0);
        dfs(0);
        //for(int i = 0; i < H.size(); i++) printf("%d ",H[i]); printf("\n");
        H2.clear(); H2.resize(n,0);
        vis.clear(); vis.resize(n,false);
        dfs2(0,0);
        //for(int i = 0; i < H2.size(); i++) printf("%d ",H2[i]); printf("\n");
        int m = INT_MAX; for(int i = 0; i < H2.size(); i++) if(H2[i]<m) m = H2[i];
        for(int i =0; i < H2.size(); i++) if(H2[i]==m) ans.push_back(i);
        return ans;
    }
    int dfs(int node) {
        //printf("%d\n",node);
        vis[node] = true;
        H[node] = 0;
        for(int i = 0; i < G[node].size(); i++) {
            if(!vis[G[node][i]]) {
                H[node] = max(H[node],dfs(G[node][i])+1);
            }
        }
        return H[node];
    }
    int dfs2(int node, int outhight) {
        //printf("%d %d ",node,outhight);
        vis[node] = true;
        H2[node] = outhight;
        int mh = outhight+1, mh2 = 0;
        bool sh = true;
        for(int i = 0; i < G[node].size(); i++) {
            if(!vis[G[node][i]]) {
                if(H[G[node][i]]+2>mh) {
                    mh2 = mh; sh = true; mh = H[G[node][i]]+2;
                }
                else if(H[G[node][i]]+2==mh) sh = false;
                else if(H[G[node][i]]+2>mh2) mh2 = H[G[node][i]]+2;
                H2[node] = max(H2[node],H[G[node][i]]+1);
            }
        }
        //printf("%d %d %d\n",H2[node],mh,mh2);
        for(int i = 0; i < G[node].size(); i++) {
            if(!vis[G[node][i]]) {
                //if(outhight>=mh) dfs2(G[node][i],outhight+1);
                if(!sh) dfs2(G[node][i],mh);
                else if(H[G[node][i]]+2 != mh) dfs2(G[node][i],mh);
                else dfs2(G[node][i],mh2);
            }
        }
        return H2[node];
    }
};

int main() {
    vector<pair<int, int> > E;
    int n;
    Solution s;
    vector<int> y;
    n = 4; int x1[] = {1, 0, 1, 2, 1, 3};
    vector<int> v1(x1, x1+6); 
    E.clear();
    for(int i = 0; i < v1.size()/2; i++) {
        pair<int, int> t(v1[2*i],v1[2*i+1]);
        E.push_back(t);
    }
    y = s.findMinHeightTrees(n,E);
    for(int i = 0; i < y.size(); i++) printf("%d ",y[i]); printf("\n");
    n = 6; int x2[] = {0, 3, 1, 3, 2, 3, 4, 3, 5, 4};
    vector<int> v2(x2, x2+sizeof(x2)/sizeof(int)); 
    E.clear();
    for(int i = 0; i < v2.size()/2; i++) {
        pair<int, int> t(v2[2*i],v2[2*i+1]);
        E.push_back(t);
    }
    y = s.findMinHeightTrees(n,E);
    for(int i = 0; i < y.size(); i++) printf("%d ",y[i]); printf("\n");
    return 0;
}