#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <string>
#include <assert.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<1) return 0;
        int p = 1;
        int r = -1;
        for(int i = 1; i < nums.size(); i++){
            if(r==-1 && nums[i]!=nums[p-1]) nums[p++] = nums[i];
            else if(r==-1 && nums[i]==nums[p-1]) {
                r = p;
                nums[p++] = nums[i];
            }else if(r>0 && nums[i]!=nums[r]) {
                nums[p++] = nums[i];
                r = -1;
            }
        }
        return p;
    }
};

int main () {
    vector<int> x;
    x.push_back(1); //x.push_back(1); x.push_back(1); x.push_back(2); x.push_back(2); x.push_back(3);
    Solution s;
    int d = s.removeDuplicates(x);
    for(int i = 0; i<d; i++){
        printf("%d ",x[i]);
    }printf("\n");
	return 0;
}