#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <assert.h>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        return m==n?m:rangeBitwiseAnd(m>>1,n>>1)<<1;
    }
};

int main () {
    Solution s;
    printf("%d\n",s.rangeBitwiseAnd(5,7));
    printf("%d\n",s.rangeBitwiseAnd(0,1));
	return 0;
}