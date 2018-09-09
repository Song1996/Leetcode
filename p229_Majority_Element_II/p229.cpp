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
        int n1, c1, n2, c2;
        c1 = 0, c2 = 0; n1 = -1, n2 = -2;
        for(int i = 0; i < nums.size(); i++) {
            //printf("%d %d %d %d %d\n",nums[i], n1, c1, n2, c2);
            if(c1==0 && nums[i]!=n2) n1 = nums[i];
            if(c2==0 && nums[i]!=n1) n2 = nums[i];
            if(nums[i]==n1) c1++;
            else if(nums[i]==n2) c2++;
            else {
                c1--; c2--;
            }
        }
        c1 = 0; c2 = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i]==n1) c1++;
            else if(nums[i]==n2) c2++;
        }
        if(c1>nums.size()/3) ans.push_back(n1);
        if(c2>nums.size()/3) ans.push_back(n2);
        return ans;
    }
};

int main () {
    int x1[] = {3,2,3};
    vector<int> v1(x1, x1+3);
    int x2[] = {1,2,2,3,2,1,1,3};
    vector<int> v2(x2, x2+8);
    Solution s;
    vector<int> y;
    for(int i = 0; i < v1.size(); i++) printf("%d ",v1[i]); printf("\n");
    y = s.majorityElement(v1);
    for(int i = 0; i < y.size(); i++) printf("%d ",y[i]); printf("\n");
    for(int i = 0; i < v2.size(); i++) printf("%d ",v2[i]); printf("\n");
    y = s.majorityElement(v2);
    for(int i = 0; i < y.size(); i++) printf("%d ",y[i]); printf("\n");
	return 0;
}