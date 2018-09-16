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
#include <cmath>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int ans = 0;
        int n = citations.size();
        for(int i = n-1; i >= 0; i--) {
            if(n-i<=ans || citations[i]<=ans) return ans;
            int m = min(n-i, citations[i]);
            ans = max(m, ans);
        }   
        return ans;
    }
};

int main() {
    int x[] = {0,1,3,5,6};
    vector<int> v(x,x+5);
    Solution s;
    printf("%d\n",s.hIndex(v));
    return 0;
}