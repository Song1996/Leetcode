#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <cassert>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        //for(auto p:nums) printf("%d ",p); printf("\n");
        vector<double> ans;
        multiset<int> s(nums.begin(),nums.begin()+k);
        auto mid = next(begin(s),k/2);
        //for(auto p = begin(s); p != end(s); p++) printf("%d ",*p); printf(": %d\n",*mid);
        ans.push_back(k%2?*mid:(*mid/2.0+*prev(mid)/2.0));
        for(int i = k; i < nums.size(); i++) {
            s.insert(nums[i]);
            if(nums[i]<*mid) mid--;
            if(nums[i-k]<=*mid) mid++;
            s.erase(s.lower_bound(nums[i-k]));
            //for(auto p = begin(s); p != end(s); p++) printf("%d ",*p); printf(": %d\n",*mid);
            ans.push_back(k%2?*mid:(*mid/2.0+*prev(mid)/2.0));
        }
        return ans;
    }
};

int main() {
    //int x[] = {5,5,8,1,4,7,1,3,8,4};
    //vector<int> v(x,x+10);
    int x[] = {1,3,-1,-3,5,3,6,7};
    vector<int> v(x,x+sizeof(x)/sizeof(int));
    Solution s;
    vector<double> y = s.medianSlidingWindow(v,3);
    for(int i = 0; i < y.size(); i++) printf("%f ",y[i]); printf("\n");
    return 0;
}