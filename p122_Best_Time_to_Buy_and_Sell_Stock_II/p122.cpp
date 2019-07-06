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
        int ans = 0;
        for(int i = 0; i < prices.size() - 1; i++) {
            int t = prices[i + 1] - prices[i];
            ans += max(t,0);
        }
        return ans;
    }
};

int main() {
  int A[] = {7,1,5,3,6,4};
  vector<int> prices(A, A + sizeof(A)/sizeof(int));
  Solution s;
  printf("%d\n",s.maxProfit(prices));
}