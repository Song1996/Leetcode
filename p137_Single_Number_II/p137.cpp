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
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0, ta;
        for(int c:nums) {
            ta = (a&~b&~c)|(~a&b&c);
            b = (b&~a&~c)|(~b&~a&c);
            a = ta;
        }
        return a|b;
    }
};

int main() {
    int x1[] = {2,2,3,2}; vector<int> v1(x1,x1+sizeof(x1)/sizeof(int));
    int x2[] = {0,1,0,1,0,1,99}; vector<int> v2(x2,x2+sizeof(x2)/sizeof(int));
    Solution s;
    printf("%d\n",s.singleNumber(v1));
    printf("%d\n",s.singleNumber(v2));
    return 0;
}