#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <assert.h>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty()) return 0;
        int t = nums[0];
        int i = 1;
        if(t>=s) return 1;
        else while(i<nums.size() && t<s) t += nums[i++];
        if(i == nums.size() && t<s) return 0;
        int ans = i;
        for(int j = 1; j < nums.size(); j++) {
            t -= nums[j-1];
            if(t>=s) ans = min(ans, i-j);
            else {
                while(i<nums.size() && t<s) t += nums[i++];
                if(i == nums.size() && t<s) return ans;
                ans = min(ans, i-j);
            }
        }
        return ans;
    }
};

int main () {
    int xlist[] = {2,3,1,2,4,3};
    vector<int> x(xlist, xlist+sizeof(xlist)/sizeof(int));
    for(int i = 0; i < x.size(); i++) printf("%d ",x[i]); printf("\n");
    Solution s;
    printf("%d\n",s.minSubArrayLen(7,x));
	return 0;
}