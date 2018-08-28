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
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        vector<vector<int> > mem(nums.size()+1);
        for(int i = 0; i < mem.size(); i++) mem[i].resize(nums.size()+1,-1);
        return dp(mem, nums, 0, nums.size());
    }
    int dp(vector<vector<int> >& mem, vector<int>& nums, int x, int y) {
        if(mem[x][y]>=0) return mem[x][y];
        if(x>=y) return 0;
        if((x+1)==y) return nums[x];
        if((x+2)==y) return max(nums[x],nums[x+1]);
        int t = -1;
        if(x!=0) t = max(dp(mem, nums, x+2, y-2)+nums[x]+nums[y-1],t);
        t = max(dp(mem, nums, x+1, y-1), t);
        t = max(dp(mem, nums, x+2, y-1)+nums[x], t);
        t = max(dp(mem, nums, x+1, y-2)+nums[y-1], t);
        mem[x][y] = t;
        return t;
    }
};

int main () {
    int x1[] = {6,6,4,8,4,3,3,10};
    vector<int> v1(x1,x1+8);
    int x2[] = {1,2,3,1};
    vector<int> v2(x2,x2+4);
    Solution s;
    printf("%d\n%d\n",s.rob(v1),s.rob(v2));
	return 0;
}