#include<vector>
class Solution {
public:
    int missingElement(std::vector<int>& nums, int k) {
        int i = 0;
        for(; i < nums.size() - 1; i++) {
            if(k > (nums[i+1] - nums[i]) - 1) {
                k -= (nums[i+1] - nums[i]) - 1;
            } else {
                return nums[i] + k;
            }
        }
        return nums[i] + k;
    }
};