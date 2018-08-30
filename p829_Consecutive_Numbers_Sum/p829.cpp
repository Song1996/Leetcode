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
using namespace std;

class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int ans = 0;
        int k = 1;
        while(true) {
            if(k%2 && N%k==0 && (k*(k-1)<2*N)) ans++;
            else if(k%2==0 && N%k==(k/2) && (k*k<2*N)) ans++;
            k++;
            if(k*(k-1)>=2*N) break;
        }
        return ans;
    }
};

int main () {
    int x;
    Solution s;
    //x = 5; printf("%d %d\n",x,s.consecutiveNumbersSum(x));
    //x = 9; printf("%d %d\n",x,s.consecutiveNumbersSum(x));
    //x = 15; printf("%d %d\n",x,s.consecutiveNumbersSum(x));
    x = 1e9; printf("%d %d\n",x,s.consecutiveNumbersSum(x));
	return 0;
}