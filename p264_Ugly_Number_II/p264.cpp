#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <assert.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> m(n);
        int i, j, k;
        i = 0; j = 0; k = 0;
        m[0] = 1;
        for(int z = 1; z < n; z ++) {
            m[z] = min(m[i]*2, min(m[j]*3, m[k]*5));
            if(m[z] == m[i]*2) i++;
            if(m[z] == m[j]*3) j++;
            if(m[z] == m[k]*5) k++;
        }
        return m.back();
    }
};

int main () {
    Solution s;
    printf("%d\n",s.nthUglyNumber(10));
	return 0;
}