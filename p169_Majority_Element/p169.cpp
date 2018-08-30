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
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = 1, ans = nums[0], mn = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i-1]) n++;
            else if(n <= mn) n = 1;
            else {
                ans = nums[i-1];
                mn = n; n = 1;
            }
        }
        if(n>mn) ans = nums[nums.size()-1];
        return ans;
    }
};

int main () {
    int xlist[] = {2,2,1,1,1,2,2};
    vector<int> x(xlist, xlist+7);
    Solution s;
    printf("%d\n",s.majorityElement(x));
	return 0;
}