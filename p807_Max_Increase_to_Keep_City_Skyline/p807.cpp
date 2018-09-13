#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <cassert>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int> >& grid) {
        int ans = 0;
        int m = grid.size(); if(m==0) return 0;
        int n = grid[0].size(); if(n==0) return 0;
        vector<int> lr(m,0);
        vector<int> tb(n,0);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]>lr[i]) lr[i] = grid[i][j];
                if(grid[i][j]>tb[j]) tb[j] = grid[i][j];
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans += min(lr[i]-grid[i][j], tb[j]-grid[i][j]);
            }
        }
        return ans;
    }
};

int main() {
    int x1[] = {3,0,8,4}; vector<int> v1(x1,x1+4);
    int x2[] = {2,4,5,7}; vector<int> v2(x2,x2+4);
    int x3[] = {9,2,6,3}; vector<int> v3(x3,x3+4);
    int x4[] = {0,3,1,0}; vector<int> v4(x4,x4+4);
    vector<vector<int> > M(4); 
    M[0] = v1, M[1] = v2, M[2] = v3, M[3] = v4;
    Solution s;
    printf("%d\n",s.maxIncreaseKeepingSkyline(M));
    return 0;
}