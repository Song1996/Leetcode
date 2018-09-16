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
    vector<int> sortArrayByParity(vector<int>& A) {
        int p = 0;
        for(int i = 0; i < A.size(); i++) {
            if(!(A[i]%2)) swap(A[i],A[p++]);
        }
        return A;
    }
};

int main() {
    int x[] = {3,1,2,4};
    vector<int> v(x,x+4);
    Solution s;
    vector<int> y = s.sortArrayByParity(v);
    for(int i = 0; i < y.size(); i++) printf("%d ",y[i]); printf("\n");
    return 0;
}