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
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> mem;
    int numSquares(int n) {
        mem.clear(); mem.resize(n+1,-1);
        return dp(n);
    }
    int dp(int n) {
        if(mem[n]>0) return mem[n];
        int k = sqrt(n);
        if(k*k==n) return 1;
        int ans = INT_MAX;
        for(int i = k; i >= 1; i--) {
            ans = min(dp(n-i*i)+1,ans);
        }
        mem[n] = ans;
        return ans;
    }
};

int main() {
    Solution s;
    printf("%d\n",s.numSquares(12));
    printf("%d\n",s.numSquares(13));
    return 0;
}