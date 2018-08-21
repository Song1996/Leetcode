#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int minx = ans;
        int maxx = ans;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i]<0) swap(minx, maxx);
            minx = min(nums[i], minx*nums[i]);
            maxx = max(nums[i], maxx*nums[i]);
            ans = max(ans, maxx);
        }
        return ans;
    }
};

int main () {
    vector<int> x;
    x.push_back(-4); x.push_back(-3);// x.push_back(-1);// x.push_back(4);
    Solution s;
    printf("%d\n",s.maxProduct(x));
}