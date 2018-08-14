#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <string>
#include <assert.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        int m = grid.size();
        if(m<=0) return 0;
        int n = grid[0].size();
        if(n<=0) return 0;
        for(int i = 0; i < m; i++) {
            if(grid[i].size()!=n) assert(0);
        }
        for(int i = n-2; i >= 0; i--) grid[m-1][i] += grid[m-1][i+1];
        for(int i = m-2; i >= 0; i--) grid[i][n-1] += grid[i+1][n-1];
        for(int i = m-2; i >= 0; i--) {
            for(int j = n-2; j >= 0; j--) {
                grid[i][j] += min(grid[i][j+1],grid[i+1][j]);
            }
        }
        return grid[0][0];
    }
};

int main () {
    vector<vector<int> > x;
    vector<int> t; t.push_back(1); t.push_back(3); t.push_back(1); x.push_back(t);
    t.clear(); t.push_back(1); t.push_back(5); t.push_back(1); x.push_back(t);
    t.clear(); t.push_back(4); t.push_back(2); t.push_back(1); x.push_back(t);
    Solution s;
    printf("%d\n",s.minPathSum(x));
	return 0;
}