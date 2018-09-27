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
    int numPermsDISequence(string S) {
        int n = S.length();
        int ans = 0;
        int mod = 1e9 + 7;
        vector<vector<int> > mem(n+1,vector<int>(n+1));
        for(int i = 0; i <= n; i++) mem[0][i] = 1;
        for(int i = 0; i < n; i++) {
            if(S[i]=='D') {
                for(int j = n - i - 1, cur = 0; j >= 0; j--) mem[i+1][j] = cur = (cur + mem[i][j+1])%mod;
            } else if(S[i]=='I') {
                for(int j = 0, cur = 0; j < n - i; j++ ) mem[i+1][j] = cur = (cur + mem[i][j])%mod;
            }
        }
        ans = mem[n][0]%mod;
        return ans;
    }
};

int main() {
    Solution s;
    string x;
    x = "IDDDIIDIIIIIIIIDIDID";
    printf("%d\n",s.numPermsDISequence(x));
    return 0;
}