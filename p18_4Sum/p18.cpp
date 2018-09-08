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
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        vector<vector<int> > ans;
        if(nums.size()<4) return ans;
        int n = nums.size();
        sort(begin(nums), end(nums));
        //for(int i = 0; i < nums.size(); i++) printf("%d ",nums[i]); printf("\n");
        //vector<int> mem(4);
        int left, right;
        for(int i = 0; i < nums.size()-3; i++) {
            if(i>0 && nums[i]==nums[i-1]) continue;
            if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            //printf("hi1 %d\n",nums[i]);
            for(int j = i+1; j < nums.size()-2; j++) {
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                if(nums[i]+nums[j]+nums[n-1]+nums[n-2]<target) continue;
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                //printf("hi2 %d\n",nums[j]);
                left = j+1, right = nums.size()-1;
                while(left<right) {
                    int sum = nums[i]+nums[j]+nums[left]+nums[right];
                    if(sum == target) {
                        //printf("%d %d %d %d\n",nums[i], nums[j], nums[left], nums[right]);
                        vector<int> temp;
                        temp.push_back(nums[i]); 
                        temp.push_back(nums[j]);
                        temp.push_back(nums[left]);
                        temp.push_back(nums[right]);
                        ans.push_back(temp);
                        left++; while(left<right && nums[left] == nums[left-1]) left++;
                        right--; while(left<right && nums[right+1] == nums[right]) right--;
                    } else if(sum<target) left++;
                    else right--;
                }
            }
         }
        return ans;
    }
};

int main () {
    int xlist[] = {-1,0,-5,-2,-2,-4,0,1,-2};
    vector<int> x(xlist, xlist+sizeof(xlist)/sizeof(int));
    Solution s;
    vector<vector<int> > y = s.fourSum(x, -9);
    printf("here\n");
    for(int i = 0; i < y.size(); i++) {
        for(int j = 0; j < y[i].size(); j++) {
            printf("%d ",y[i][j]);
        }printf("\n");
    }
	return 0;
}