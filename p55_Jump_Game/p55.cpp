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
    bool canJump(vector<int>& nums) {
        /*for(vector<int>::iterator it = nums.begin(); it!=nums.end(); it++){
            printf("%d ",*it);
        }printf("\n");*/
        int farest = 0;
        int cur = 0;
        while(cur<nums.size()&&cur<=farest) {
            if(farest<(nums[cur]+cur)) farest = nums[cur]+cur;
            cur ++;
        }
        return cur==nums.size();
    }
};

int main () {
    Solution s;
    int xlist1[] = {2,3,1,1,4};
    vector<int> x1(xlist1, xlist1+sizeof(xlist1)/sizeof(int));
    printf("%s\n", s.canJump(x1)?"true":"false");
    int xlist2[] = {3,2,1,0,4};
    vector<int> x2(xlist2, xlist2+sizeof(xlist2)/sizeof(int));
    printf("%s\n", s.canJump(x2)?"true":"false");    
	return 0;
}

