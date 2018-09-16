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

typedef unsigned int uint;
class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        return helper(A,0,A.size())%1000000007;
    }
    uint helper(vector<int>& A, uint x, uint y) {
        if(y==x) return 0;
        if(y-x==1) return A[x];
        uint ans = 0;
        uint m = INT_MAX, p = -1;
        for(int i = x; i < y; i++) {
            if(A[i]<m) {
                m = A[i]; p = i;
            }
        }
        ans += ((y-x)+(p-x)*(y-p-1))*m;
        return (ans + helper(A,x,p) + helper(A,p+1,y))%1000000007;
    }
        /*int sumSubarrayMins(vector<int>& A) {
            int m;
            unsigned int ans = 0;
            for(int i = 0; i < A.size(); i++) {
                m = A[i]; ans += m;
                ans = ans%(1000000007);
                for(int j = i+1; j < A.size(); j++) {
                    if(A[j]<m) m = A[j];
                    ans += m;
                    ans = ans%(1000000007);
                }
            }
            return ans%(1000000007);
        }*/
};

int main() {
    Solution s;
    int x[] = {3,1,2,4};
    vector<int> v(x,x+4);
    //int x[] = {85};
    //vector<int> v(x,x+1);
    printf("%d\n",s.sumSubarrayMins(v));
    return 0;
}