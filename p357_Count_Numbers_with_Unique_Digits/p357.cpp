#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <assert.h>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n>10) return 0;
        if(n == 0) return 1;
        if(n == 1) return 10;
        vector<int> mem(11, -1);
        mem[1] = 10;
        int ans = 10;
        for(int i = 2; i <= n; i++) ans += (dp(i, mem)/10)*9;
        return ans;
    }
    int dp(int n, vector<int>& mem) {
        if(mem[n]>0) return mem[n];
        mem[n] = (11-n)*dp(n-1, mem);
        return mem[n];
    }
};

int main () {
    Solution s;
    printf("%d\n",s.countNumbersWithUniqueDigits(3));
	return 0;
}