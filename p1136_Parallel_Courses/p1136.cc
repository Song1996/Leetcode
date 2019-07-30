#include <queue>
#include <vector>
#include <cstring>
using namespace std;
class Solution {
    constexpr static const int MAX_N = 5000;
    int inedges[MAX_N+1];
    vector<int> outedges[MAX_N+1];
    queue<int> q;
    int days[MAX_N+1];
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        memset(days, 0 , sizeof(days));
        while(!q.empty()) q.pop();
        for(int i = 1; i < N; i++) {
            inedges[i]=0;
            outedges[i].clear();
        }
        for(auto e: relations) {
            inedges[e[1]]++;
            outedges[e[0]].push_back(e[1]);
        }
        for(int i = 1; i <= N; i++) {
            if(inedges[i]==0) {
                days[i] = 1;
                q.push(i);
            }
        }
        while(!q.empty()) {
            for(auto v: outedges[q.front()]) {
                days[v] = days[q.front()]+1;
                inedges[v]--;
                if(inedges[v]==0) {
                    q.push(v);
                }
            }
            q.pop();
        }
        int ans = 0;
        for(int i = 1; i <= N; i++) {
            if(days[i] == 0) return -1;
            ans = max(ans, days[i]);
        }
        return ans;
    }
};