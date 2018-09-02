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
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int c1, c2, n1, n2;
        c1 = 0, c2 = 0, n1 = 0, n2 = 1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i]==n1) c1++;
            else if(nums[i]==n2) c2++;
            else if(c1==0) {
                n1 = nums[i]; c1++;
            } else if(c2==0) {
                n2 = nums[i]; c2++;
            } else {
                c1--; c2--;
            }
        }
        int c = 0;
        for(int i = 0; i < nums.size(); i++) if(nums[i]==n1) c++;
        if(c>nums.size()/3)ans.push_back(n1);
        c = 0;
        for(int i = 0; i < nums.size(); i++) if(nums[i]==n2) c++;
        if(c>nums.size()/3)ans.push_back(n2);
        return ans;
    }
};

int main () {
    int x1[] = {3,2,3};
    vector<int> v1(x1, x1+3);
    int x2[] = {1,1,1,3,3,2,2,2};
    vector<int> v2(x2, x2+8);
    Solution s;
    vector<int> y;
    y = s.majorityElement(v1);
    for(int i = 0; i < y.size(); i++) printf("%d ",y[i]); printf("\n");
    y = s.majorityElement(v2);
    for(int i = 0; i < y.size(); i++) printf("%d ",y[i]); printf("\n");
	return 0;
}