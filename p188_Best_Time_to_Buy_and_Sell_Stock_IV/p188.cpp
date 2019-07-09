#include <iostream>
#include <vector>

using namespace std;

// for any range, if there exist a 'downstair' (prices[i+1] < prices[i]), 
// split this range into two subrange will generate a larger range. 
// So greedy is good.

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.empty()) return 0;
        if(k==0) return 0;
        k = min(k, int( prices.size()/2 ) + 1 );
        vector<int> odp(k, 0);
        vector<int> ndp(k, 0);
        vector<int> max_sells(k,0);
        int ans = 0;
        for(int i = 1; i < prices.size(); i++) {
            for(int j = 0; j < k; j++){
                ndp[j] = max(0, odp[j] + prices[i] - prices[i-1]);
                ndp[j] = max(ndp[j], max_sells[j] + prices[i] - prices[i-1]);
            }
            for(int j = 1; j < k; j++) {
                max_sells[j] = max(max_sells[j], ndp[j-1]);
            }
            ans = max(ans, ndp[k-1]);
            swap(odp, ndp);
        }
        return ans; 
    }
};

int main() {
  //int A[] = {3,3,5,0,0,3,1,4};
  //int A[] = {7,6,4,3,1};
  int A[] = {2,4,1};
  vector<int> prices(A, A + sizeof(A)/sizeof(int));
  Solution s;
  printf("%d\n",s.maxProfit(2,prices));
}