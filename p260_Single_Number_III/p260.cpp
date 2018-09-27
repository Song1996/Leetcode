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
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans(2);
        int n = 0;
        for(int c:nums) n ^= c;
        int m = 1;
        while(m&&!(n&m)) m <<= 1;
        for(int c:nums) {
            if(c&m) ans[0] ^= c;
            else ans[1] ^= c;
        }
        return ans;
    }
};

int main() {
    int x1[] = {1,2,1,3,2,5}; vector<int> v1(x1, x1+sizeof(x1)/sizeof(int));
    Solution s;
    vector<int> y = s.singleNumber(v1);
    for(int i:y) printf("%d\n",i);
    return 0;
}