#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <assert.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j]=='1') {
                    ans ++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<char> >& grid, int x, int y) {
        grid[x][y] = '0';
        if(x+1<grid.size() && grid[x+1][y]=='1') dfs(grid, x+1, y);
        if(x-1>=0 && grid[x-1][y]=='1') dfs(grid, x-1, y);
        if(y+1<grid[x].size() && grid[x][y+1]=='1') dfs(grid, x, y+1);
        if(y-1>=0 && grid[x][y-1]=='1') dfs(grid, x, y-1);
    }
};

int main () {
    vector<vector<char> > x;
    vector<char> t;
    t.push_back('1'); t.push_back('1'); t.push_back('0'); t.push_back('0'); t.push_back('0'); 
    x.push_back(t); t.clear();
    t.push_back('1'); t.push_back('1'); t.push_back('0'); t.push_back('0'); t.push_back('0'); 
    x.push_back(t); t.clear();
    t.push_back('0'); t.push_back('0'); t.push_back('1'); t.push_back('0'); t.push_back('0'); 
    x.push_back(t); t.clear();
    t.push_back('0'); t.push_back('0'); t.push_back('0'); t.push_back('1'); t.push_back('1'); 
    x.push_back(t); t.clear();
    Solution s;
    printf("%d\n",s.numIslands(x));
	return 0;
}