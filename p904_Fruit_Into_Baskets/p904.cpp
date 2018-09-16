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
    int totalFruit(vector<int>& tree) {
        int ans = INT_MIN;
        int b1n = 1, b2n = 0, b1t = tree[0], b2t = -1;
        int i = 1; while(i<tree.size() && tree[i]==b1t) {b1n++; i++;}
        if(i==tree.size()) return b1n;
        b2t = tree[i++]; b2n = 1; ans = b2n + b1n;
        int sp = 0;
        for(;i<tree.size();i++) {
            if(tree[i]==b1t) {
                b1n++;
                ans = max(ans, b1n+b2n);
            } else if(tree[i]==b2t) {
                b2n++;
                ans = max(ans, b1n+b2n);
            } else {
                while(b1n>0&&b2n>0) {
                    if(tree[sp]==b1t) b1n--;
                    else b2n--;
                    sp++;
                }
                if(b1n==0) {
                    b1t = tree[i]; b1n = 1;
                } else {
                    b2t = tree[i]; b2n = 1;
                }
                ans = max(ans, b1n+b2n);
            }
        }
        return ans;
    }
};

int main() {
    int x1[] = {1,2,1}; vector<int> v1(x1,x1+3);
    int x2[] = {0,1,2,2}; vector<int> v2(x2,x2+4);
    int x3[] = {1,2,3,2,2}; vector<int> v3(x3,x3+5);
    int x4[] = {3,3,3,1,2,1,1,2,3,3,4}; vector<int> v4(x4,x4+11);
    int x5[] = {1,0,1,4,1,4,1,2,3}; vector<int> v5(x5,x5+9);
    vector<int> V[] = {v1,v2,v3,v4,v5};
    vector<vector<int> > x(V,V+5);
    Solution s;
    for(int i = 0; i < x.size(); i++) {
        for(int j = 0; j < x[i].size(); j++) printf("%d ",x[i][j]);
        printf("\n");
        printf("%d\n",s.totalFruit(x[i]));
    }
    return 0;
}