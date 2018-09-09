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
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        vector<int> temp(nums.begin(), nums.end());
        sort(temp.begin(), temp.end());
        //for(int i = 0; i < n; i++) printf("%d ",nums[i]); printf("\n");
        int left = 0, right = n-1;
        while(left<right) {
            int sum = temp[left]+temp[right];
            if(sum == target) {
                ans.push_back(temp[left]); ans.push_back(temp[right]);  break;
            } else if(sum < target) left++;
            else right--;
        }
        for(int i = 0; i < ans.size(); i++) {
            for(int j = 0; j < n; j++) {
                if(ans[i]==nums[j]) {
                    if(i>0 && j==ans[i-1]) continue;
                    ans[i] = j; break;
                }
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}