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
    int kEmptySlots(vector<int>& flowers, int k) {
        if(flowers.size()<2) return -1;
        set<int> mem;
        mem.insert(flowers[0]);
        int ans = -1;
        for(int i = 1; i < flowers.size(); i++) {
            set<int>::iterator lb = mem.lower_bound(flowers[i]-k-1);
            set<int>::iterator ub = mem.upper_bound(flowers[i]-k-1);
            if( lb != mem.end() && *lb==flowers[i]-k-1) {
                if(ub==mem.end()||*ub>flowers[i]) return i+1;
            }
            ub = mem.upper_bound(flowers[i]);
            if(ub!=mem.end() && *ub == flowers[i]+k+1) return i+1;
            mem.insert(flowers[i]);
        }
        return ans;
    }
};

int main() {
    return 0;
}