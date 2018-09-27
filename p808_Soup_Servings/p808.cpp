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
    typedef unsigned long long ull;
    inline ull key(int i,int j) { return (ull(i))<<32|j;}
    unordered_map<ull,double> mem;
    double soupServings(int N) {
        if(N>=7000) return 1.0;
        mem.clear();
        //printf("hello\n");
        return helper(N,N);
    }
    double helper(int m, int n) {
        if(n<=0) return 0.5 * (m<=0?1.0:0.0);
        else if(m<=0) return 1;
        ull p = key(m,n);
        if(mem.find(p)!=mem.end()) return mem[p];
        mem[p] = 0.25 * helper(m-100,n) + 0.25 * helper(m-75,n-25) + 0.25 * helper(m-50,n-50) + 0.25 * helper(m-25,n-75);
        return mem[p];
    }
};

int main() {
    Solution s;
    printf("%f\n",s.soupServings(50));
    printf("%f\n",s.soupServings(5000));
    printf("%f\n",s.soupServings(7000));
    printf("%f\n",s.soupServings(10000));
    printf("%f\n",s.soupServings(50000));
    return 0;
}