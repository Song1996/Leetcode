#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    int sumOfDigits(vector<int>& A) {
        int m = INT_MAX;
        for(int i = 0; i < A.size(); i++) {
            m = min(m, A[i]);
        }
        int ans = 0;
        while(m > 0) {
            ans += m%10;
            m /= 10;
        }
        return 1 - ans%2;
    }
};