#include <iostream>
#include <vector>

using namespace std;

// for any range, if there exist a 'downstair' (prices[i+1] < prices[i]), 
// split this range into two subrange will generate a larger range. 
// So greedy is good.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        // odp[0], max profit for 1 sell at i-1
        // odp[1], max profit for 2 sells at i-1
        // ndp[0], max profit for 1 sell at i
        // ndp[1], max profit for 2 sells at i
        // max_1sell, max profit for 1 sell before i
        int odp[2] = {0, 0};
        int ndp[2] = {0, 0};
        int max_1sell = 0;
        int ans = 0;
        for(int i = 1; i < prices.size(); i++) {
            ndp[0] = max(0, odp[0] + prices[i] - prices[i-1]);
            ndp[1] = max(0, odp[1] + prices[i] - prices[i-1]);
            if(i > 2) {
                ndp[1] = max(ndp[1], max_1sell + prices[i] - prices[i-1]);
            }
            max_1sell = max(max_1sell, ndp[0]);
            ans = max(ans, ndp[1]);
            odp[0] = ndp[0];
            odp[1] = ndp[1];
        }
        return ans;
    }
};

int main() {
  //int A[] = {3,3,5,0,0,3,1,4};
  int A[] = {7,6,4,3,1};
  vector<int> prices(A, A + sizeof(A)/sizeof(int));
  Solution s;
  printf("%d\n",s.maxProfit(prices));
}