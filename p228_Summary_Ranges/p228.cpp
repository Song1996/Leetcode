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
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size()==0) return ans;
        int p1 = 0; int p2 = -1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i]==nums[i-1]+1) p2 = i;
            else if(p2 == -1){
                ans.push_back(to_string(nums[p1]));
                p1 = i;
            }else {
                ans.push_back(to_string(nums[p1])+"->"+to_string(nums[p2]));
                p1 = i; p2 = -1;
            }
        }
        if(p2 == -1) ans.push_back(to_string(nums[p1]));
        else ans.push_back(to_string(nums[p1])+"->"+to_string(nums[p2]));
        return ans;
    }
};

int main () {
    int x1[] = {0,1,2,4,5,7};
    vector<int> v1(x1, x1+6);
    int x2[] = {0,2,3,4,6,8,9};
    vector<int> v2(x2, x2+7);
    Solution s; vector<string> y;
    y = s.summaryRanges(v1); 
    for(int i = 0; i < y.size(); i++) printf("%s ",y[i].c_str()); printf("\n");
    y = s.summaryRanges(v2); 
    for(int i = 0; i < y.size(); i++) printf("%s ",y[i].c_str()); printf("\n");
	return 0;
}