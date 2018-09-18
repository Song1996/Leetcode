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
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int> >& board) {
        int dirlist[] = {1,-1,3,-3}; vector<int> dir(dirlist,dirlist+4);
        string s(6,' ');
        string tar(6,' ');
        int p = -1;
        for(int i = 0; i < 6; i++) {
            if(board[i/3][i%3]==0) p = i;
            s[i] = board[i/3][i%3]+'0';
            tar[i] = (i+1)%6+'0';
        }
        //printf("%s %s\n",s.c_str(),tar.c_str());
        unordered_map<string,string> vis;
        queue<string> q;
        queue<int> d;
        queue<int> ps;
        int ans = 0;
        q.push(s); d.push(0); ps.push(p);
        vis[s] = string("");
        while(!q.empty()) {
            s = q.front(); q.pop();
            ans = d.front(); d.pop();
            //printf("%s %d\n",s.c_str(),ans);
            if(s==tar) {
                /*while(s!="") {
                    printf("%s -> ",s.c_str());
                    s = vis[s];
                }*/
                return ans;
            }
            p = ps.front(); ps.pop();
            for(int i:dir) {
                if(p==2&&i==1) continue;
                if(p==3&&i==-1) continue;
                if(i+p<6 && i+p>=0) {
                    swap(s[p],s[i+p]);
                    if(vis.find(s)==vis.end()) {
                        vis[s] = s;
                        swap(vis[s][p],vis[s][i+p]);
                        q.push(s); d.push(ans+1); ps.push(i+p);
                        //printf("%s %s\n",s.c_str(),vis[s].c_str());
                    }
                    swap(s[p],s[i+p]);
                }
            }
        }
        return -1;
    }
};

int main() {
    int x1[] = {3,2,4}; int x2[] = {1,5,0};
    vector<int> v1(x1,x1+3); vector<int> v2(x2,x2+3);
    vector<int> B[] = {v1,v2};
    vector<vector<int> > board(B,B+2);
    Solution s;
    printf("%d\n",s.slidingPuzzle(board));
    return 0;
}