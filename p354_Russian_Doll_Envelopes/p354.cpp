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
    static bool mycmp(pair<int,int> p1, pair<int,int> p2) {
        return p1.first<p2.first;
    }
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int n = envelopes.size();
        if(n==0) return 0;
        sort(begin(envelopes),end(envelopes),mycmp);
        vector<int> mem(n);
        mem[n-1] = 1;
        int ans = 1;
        for(int i = n-2; i >= 0; i--) {
            int tans = 1;
            for(int j = i+1; j < n; j++) {
                if(envelopes[i].first<envelopes[j].first && envelopes[i].second<envelopes[j].second) tans = max(tans, mem[j]+1);
            }
            mem[i] = tans;
            ans = max(ans, tans);
        }
        return ans;
    }
};

int main() {
    return 0;
}
