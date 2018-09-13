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
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        vector<int> mem(n);
        mem[n-1] = 1;
        int ans = 1;
        for(int i = n-2; i >= 0; i--) {
            int tans = 1;
            for(int j = i+1; j < n; j++) {
                if(nums[j]>nums[i]) tans = max(tans, mem[j]+1);
            }
            mem[i] = tans;
            ans = max(tans,ans);
        }
        return ans;
    }
};

int main() {
    return 0;
}