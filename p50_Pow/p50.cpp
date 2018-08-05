#include <stdlib.h>
#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        B = 0x80000000;
        if (n==0) {
            return 1.0;
        } 
        bool nflag = (n<0);
        n = abs(n);
        int pos = 31;
        while (!(B&n)) {
            pos --;
            B >>= 1;
        }
        saved_pow[0] = x;
        for (int i = 1; i <= pos; i++) {
            saved_pow[i] = saved_pow[i-1]*saved_pow[i-1];
        }
        double result = 1.0;
        while (B) {
            if (B&n) {
                result *= saved_pow[pos];
            }
            pos --;
            B >>= 1;
        }
        if (nflag) {
            result = 1/result;
        }
        return result;
    }
private:
    double saved_pow[33];
    unsigned int B;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    class Solution s = Solution();
    printf("answer %f\n",s.myPow(2.0,10));
    printf("answer %f\n",s.myPow(2.0,-2));
    printf("answer %f\n",s.myPow(2.10000, 3));
}