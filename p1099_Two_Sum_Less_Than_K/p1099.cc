#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        if(A.size() < 2) return -1;
        sort(A.begin(), A.end());
        if(A[0]+A[1] >= K) return -1;
        int p1 = 0, p2 = A.size() - 1;
        while(A[p1] + A[p2] >= K) p2--;
        int ans = A[p1] + A[p2];
        while(p2 > p1) {
            while(A[p1+1] + A[p2] < K && p1+1 < p2) {
                p1++;
            }
            ans = max(ans, A[p1]+A[p2]);
            p2--;
        }
        return ans;
    }
};