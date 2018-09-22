#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <cassert>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        unsigned ans = 1, base = a;
        base %= 1337;
        for(int i = 0; i < b.size(); i++) {
            int n = b[b.size()-1-i];
            for(int i = 0; i < n; i++) {
                ans *= base;
                ans %= 1337;
            }
            //printf("%u;\n",base);
            unsigned t = base * base % 1337;
            t *= base; t %= 1337;
            base *= t; base %= 1337;
            base *= t; base %= 1337;
            base *= t; base %= 1337;
        }
        return ans%1337;
    }
};
int main() {
    Solution s;
    int x[] = {2,0,0}; vector<int> v(x,x+sizeof(x)/sizeof(int));
    printf("%d\n",s.superPow(2147483647,v));
    return 0;
}