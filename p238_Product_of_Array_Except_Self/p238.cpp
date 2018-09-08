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
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ps(n), ns(n), ans(n);
        ps[0] = nums[0]; for(int i = 1; i < n; i++) ps[i] = ps[i-1] * nums[i];
        ns[n-1] = nums[n-1]; for(int i = n-2; i >= 0; i--) ns[i] = ns[i+1] * nums[i];
        for(int i = 0; i < n; i++) {
            if(i==0) ans[i] = ns[i+1];
            else if(i==n-1) ans[i] = ps[i-1];
            else ans[i] = ns[i+1]*ps[i-1];
        }
        return ans;
    }
};

int main() {
    int xlist[] = {1,2,3,4};
    vector<int> x(xlist, xlist+4);
    Solution s;
    vector<int> y = s.productExceptSelf(x);
    for(int i = 0; i < y.size(); i++) printf("%d ",y[i]); printf("\n");
    return 0;
}