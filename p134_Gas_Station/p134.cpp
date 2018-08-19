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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        if(n<1) return -1;
        for(int i = 0; i < n; i++) {
            gas[i] -= cost[i];
        }
        for(int i = 0; i < n; i++) printf("%d ",gas[i]); printf("\n");
        int minp = 0;
        for(int i = 1; i<n; i++) {
            gas[i] += gas[i-1];
            if(gas[i]<gas[minp]) minp = i;
        }
        if(gas[n-1]<0) return -1;
        else return minp+1;
    }
};

int main () {
    vector<int> x1;
    x1.push_back(1); x1.push_back(2); x1.push_back(3); x1.push_back(4); x1.push_back(5);
    vector<int> x2;
    x2.push_back(3); x2.push_back(4); x2.push_back(5); x2.push_back(1); x2.push_back(2); 
    Solution s;
    printf("%d\n",s.canCompleteCircuit(x1,x2));
	return 0;
}