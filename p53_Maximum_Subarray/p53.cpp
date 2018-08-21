#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int maxx = ans;
        for(int i = 1; i < nums.size(); i++) {
            maxx = max(nums[i], nums[i]+maxx);
            ans = max(ans, maxx);
        }
        return ans;
    }
};

int main() {
    int listx[] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> x(listx, listx+sizeof(listx)/sizeof(int));
    for(int i = 0; i < x.size(); i++) printf("%d ",x[i]); printf("\n");
    Solution s;
    printf("%d\n",s.maxSubArray(x));
    return 0;
}