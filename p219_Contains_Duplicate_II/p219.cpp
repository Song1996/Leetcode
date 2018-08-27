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
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> h;
        for(int i = 0; i < nums.size() && i <= k; i++) {
            if(h.find(nums[i])!=h.end()) return true;
            h[nums[i]] = 1;
        }
        for(int i = k+1; i < nums.size(); i++) {
            h[nums[i-k-1]] = 0;
            if(h.find(nums[i])!=h.end() && h[nums[i]]==1) return true;
            h[nums[i]] = 1;
        }
        return false;
    }
};

int main () {
    int xlist[] = {1,2,3,1,2,3};
    vector<int> x(xlist, xlist+4);
    Solution s;
    printf("%s\n",s.containsNearbyDuplicate(x,2)?"true":"false");
	return 0;
}