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
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m<1) return 0;
        int n = obstacleGrid[0].size();
        if(n<1) return 0;
        if(m>100||n>100) return 0;
        memset(mem, -1, sizeof(mem));
        if(obstacleGrid[0][0]==1) return 0;
        if(obstacleGrid[m-1][n-1]==1) return 0;
        mem[0][0] = 1;
        for(int i = 1; i < m; i++) {
            if(obstacleGrid[m-1-i][n-1]==1) mem[i][0] = 0;
            else mem[i][0] = mem[i-1][0];
        }
        for(int i = 1; i < n; i++) {
            if(obstacleGrid[m-1][n-1-i]==1) mem[0][i] = 0;
            else mem[0][i] = mem[0][i-1];
        }
        return dp(obstacleGrid, m-1, n-1, m-1, n-1);
    }
    int dp(vector<vector<int> >& O, int m, int n, int M, int N){
        if(mem[m][n]<0) {
            if( (!O[M-(m-1)][N-n]) && (!O[M-m][N-(n-1)]) ) mem[m][n] = dp(O,m-1,n,M,N)+dp(O,m,n-1,M,N);
            else if(!O[M-(m-1)][N-n]) mem[m][n] = dp(O,m-1,n,M,N);
            else if(!O[M-m][N-(n-1)]) mem[m][n] = dp(O,m,n-1,M,N);
            else mem[m][n] = 0;
        }
        return mem[m][n];
    }
    int mem[100][100];
};

int main () {
    Solution s;
    vector<vector<int> >O;
    for(int i = 0; i < 4; i ++){
        vector<int> t;
        for(int j = 0; j < 4; j++){
            t.push_back(0);
        }
        O.push_back(t);
    }
    O[1][1] = 1;
    O[2][2] = 1;
    printf("%d\n",s.uniquePathsWithObstacles(O));
	return 0;
}