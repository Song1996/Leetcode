#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        //for(int i = 0; i < nums.size(); i++) printf("%d ", nums[i]); printf("\n");
        int ans;
        int l = nums.size();
        if(nums[1]<0) {
            ans = nums[0]*nums[1]*nums[l-1];
            ans = max(ans, nums[l-1]*nums[l-2]*nums[l-3]);
        }else ans = nums[l-1]*nums[l-2]*nums[l-3];
        return ans;
    }
};

int main() {
    vector<int> x;
    for(int i = 0; i < 9; i++) x.push_back(-1*i);
    for(int i = 1; i < 4; i++) x.push_back(i);
    Solution s;
    printf("%d\n",s.maximumProduct(x));
}