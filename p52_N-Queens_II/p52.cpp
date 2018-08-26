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
    int totalNQueens(int n) {
        vector<int> mem(n);
        for(int i = 0; i < n; i++) mem[i] = i;
        int ans = 0;
        dfs(ans, mem, 0);
        return ans;
    }
    void dfs(int& ans, vector<int>& mem, int d) {
        if(d==mem.size()) {
            ans++;
            return;
        }
        for(int i = d; i < mem.size(); i++) {
            bool flag = true;
            for(int j = 0; j < d; j++) {
                if(abs(mem[j]-mem[i]) == d-j) {
                    flag = false; break;
                }
            }
            if(flag) {
                swap(mem[i],mem[d]);
                dfs(ans, mem, d+1);
                swap(mem[i],mem[d]);
            }
        }
    }
};

int main () {
    Solution s;
    printf("%d\n",s.totalNQueens(8));
	return 0;
}