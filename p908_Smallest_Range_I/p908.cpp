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
    int smallestRangeI(vector<int>& A, int K) {
        int min_x = INT_MAX, max_x = INT_MIN;
        for(int n:A) {
            if(n<min_x) min_x = n;
            if(n>max_x) max_x = n;
        }
        int ans = (max_x - K) - (min_x + K);
        return ans>0?ans:0;
    }
};

int main() {
    Solution s;
    int x1[] = {1}; vector<int> v1(x1,x1+sizeof(x1)/sizeof(int));
    printf("%d\n",s.smallestRangeI(v1,0));
    int x2[] = {0,10}; vector<int> v2(x2,x2+sizeof(x2)/sizeof(int));
    printf("%d\n",s.smallestRangeI(v2,2));
    int x3[] = {1,3,6}; vector<int> v3(x3,x3+sizeof(x3)/sizeof(int));
    printf("%d\n",s.smallestRangeI(v3,3));
    return 0;
}