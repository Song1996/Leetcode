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
    bool xorGame(vector<int>& nums) {
        int xo = 0;
        for(int n:nums) xo ^= n;
        return xo==0 || nums.size()%2==0;
    }
};

int main() {
    return 0;
}