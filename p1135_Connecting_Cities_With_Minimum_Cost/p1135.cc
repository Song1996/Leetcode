#include <queue>
#include <vector>
using namespace std;

class Solution {
    class edge{
    public:
        int city1;
        int city2;
        int cost;
        edge(int t1, int t2, int t3) {
            city1 = t1;
            city2 = t2;
            cost = t3;
        }
        void print() const {
            printf("edge %d %d %d\n", city1, city2, cost);
        }
    };
    
    class mycompclass{
        public:
        const bool operator () (const edge& e1,const edge& e2) const {
            return e1.cost > e2.cost;
        }
    };
    
    constexpr static const int MAX_N = 10000;
    int G[MAX_N+1];
    
    int find(int v) {
        if(G[v]) {
            G[v] = find(G[v]);
            return G[v];
        } else return v;
    }
    
    void Union(int v1, int v2) {
        G[find(v2)] = find(v1);
    }
public:
    
    
    int minimumCost(int N, vector<vector<int>>& connections) {
        //priority_queue<edge, vector<edge>, greater<edge> > pq;
        priority_queue<edge, vector<edge>, mycompclass > pq;
        for(auto v: connections) {
            pq.push(edge(v[0], v[1], v[2]));
        }
        memset(G, 0, sizeof(G));
        int ans = 0;
        while(!pq.empty()) {
            edge e = pq.top();
            if(find(e.city1) != find(e.city2)) {
                Union(e.city1, e.city2);
                ans += e.cost;
            }
            pq.pop();
        }
        int numIslands = 0;
        for(int i = 1; i <= N; i++) {
            //printf("%d\n", G[i]);
            if(!G[i]) numIslands ++;
        }
        return numIslands==1?ans:-1;
    }
};