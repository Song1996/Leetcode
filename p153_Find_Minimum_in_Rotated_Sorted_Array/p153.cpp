#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        if(nums[l]<nums[r]) return nums[l];
        while(l<r-1) {
            int mid = l + (r-l)/2;
            if(nums[mid]>nums[r]) l = mid;
            else r = mid;
            //printf("%d %d\n",l,r);
        }
        return nums[r];
    }
};

int main() {
    vector<int> x;
    x.push_back(4); x.push_back(5); x.push_back(6); x.push_back(7); x.push_back(0); x.push_back(1); x.push_back(2);
    Solution s;
    printf("%d\n",s.findMin(x));
    return 0;
}