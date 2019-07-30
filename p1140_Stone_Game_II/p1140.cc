#include<vector>
#include<climits>
using namespace std;

class Solution {
    int mem[101][100];
    int subsum[101];
    int n;
public:
    int dfs(int start, int m) {
        if(n - start <= 2 * m) return subsum[n] - subsum[start];
        if(mem[start][m]) return mem[start][m];
        int ans = INT_MIN;
        for(int x = 1; x <= 2*m && x < n - start; x++) {
            ans = max(ans, subsum[n] - subsum[start] - dfs(start + x, max(x,m)));
        }            
        mem[start][m] = ans;
        return ans;
    }
    int stoneGameII(vector<int>& piles) {
        memset(subsum, 0, sizeof(subsum));
        memset(mem, 0, sizeof(mem));
        n = piles.size();
        for(int i = 0; i < piles.size(); i++) {
            subsum[i+1] = piles[i] + subsum[i];
        }
        return dfs(0,1);
    }
};