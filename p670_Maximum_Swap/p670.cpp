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
    vector<int> mem;
    vector<int> mmem;
    int maximumSwap(int num) {
        mem.clear(); mem.resize(10, 0);
        mmem.clear(); mmem.resize(10,0);
        int l = 0;
        while(num) {
            mem[l] = num%10;
            if(l==0) mmem[l] = mem[l];
            else mmem[l] = max(mem[l],mmem[l-1]);
            num /= 10;
            l++;
        }
        for(int i = l-1; i >= 1; i--) {
            if(mmem[i]!=mem[i]) {
                for(int j = 0; j < i; j++) {
                    if(mem[j]==mmem[i]) swap(mem[i],mem[j]);
                }
                break;
            }
        }
        int ans = 0;
        for(int i = l - 1; i >= 0; i--) {
            ans *= 10; ans += mem[i];
        }
        return ans;
    }
};

int main() {
    Solution s;
    printf("%d\n",s.maximumSwap(2736));
    printf("%d\n",s.maximumSwap(9973));
    return 0;
}