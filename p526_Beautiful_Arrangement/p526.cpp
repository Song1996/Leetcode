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
    int countArrangement(int N) {
        vector<int> mem(N);
        for(int i = 0; i < N; i++) mem[i] = i+1;
        int ans = 0;
        dfs(ans, mem, 0);
        return ans;
    }
    void dfs(int& ans, vector<int>& mem, int pos) {
        if(pos==mem.size()) {
            ans++;
            return;
        }
        if((pos+1)%mem[pos]==0 || mem[pos]%(pos+1)==0) dfs(ans, mem, pos+1);
        for(int i = 1; i+pos<mem.size(); i++) {
            if((pos+1)%mem[pos+i]==0 || mem[pos+i]%(pos+1)==0){
                swap(mem[pos+i], mem[pos]);
                dfs(ans, mem, pos+1);
                swap(mem[pos+i], mem[pos]);
            }
        }
    }
};

int main () {
    Solution s;
    printf("%d\n",s.countArrangement(2));
	return 0;
}