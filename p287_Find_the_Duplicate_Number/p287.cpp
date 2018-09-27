#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <cassert>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size()<2) return -1;
        int ans;
        int n = nums.size() - 1;
        int l = 1, r = n, mid;
        while(l < r - 1) {
            mid = l + (r-l)/2;
            n = 0;
            for(int i:nums) if(i<=mid) n++;
            if(n<=mid) l = mid+1;
            else r = mid;
        }
        n = 0;
        for(int i:nums) if(i<=l) n++;
        if(n>l) return l;
        return r;
    }
};

int main() {
    Solution s;
    int x1[] = {1,3,4,2,2};
    vector<int> v1(x1, x1+sizeof(x1)/sizeof(int));
    printf("%d\n",s.findDuplicate(v1));
    int x2[] = {3,1,3,4,2};
    vector<int> v2(x2, x2+sizeof(x2)/sizeof(int));
    printf("%d\n",s.findDuplicate(v2));
    return 0;
}