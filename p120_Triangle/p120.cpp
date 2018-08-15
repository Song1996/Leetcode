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
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()<1) return 0;
        for(int i = triangle.size()-2; i >=0 ; i--) {
            for(int j = 0; j < triangle[i].size(); j++) {
                triangle[i][j] += min(triangle[i+1][j],triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
    int dfs(vector<vector<int>>& triangle, int p, int d) {
        if(d==(triangle.size()-1)) return triangle[d][p];
        int r1 = dfs(triangle, p, d+1);
        int r2 = dfs(triangle, p+1, d+1);
        return r1<r2?(r1+triangle[d][p]):(r2+triangle[d][p]);
    }
};

int main () {
	return 0;
}