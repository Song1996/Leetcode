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
    int uniquePaths(int m, int n) {
        if(m<1||n<1) return 0;
        if(m>100||n>100) return 0;
        memset(mem, -1, sizeof(mem));
        for(int i = 0; i < 100; i++) {
            mem[0][i] = 1;
            mem[i][0] = 1;
        }
        return dp(m-1,n-1);
    }
    int dp(int m, int n){
        if(mem[m][n]<0) mem[m][n] = dp(m-1,n)+dp(m,n-1);
        return mem[m][n];
    }
    int mem[100][100];
};

int main () {
    Solution s;
    int m , n;
    m = 3, n =2;
    printf("%d %d %d\n",m,n,s.uniquePaths(m,n));
    m = 7, n =3;
    printf("%d %d %d\n",m,n,s.uniquePaths(m,n));
	return 0;
}

