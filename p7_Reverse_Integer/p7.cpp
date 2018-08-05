#include <iostream>
//#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x==0) return 0;
        bool nflag = false;
        if (x<0) {
            nflag = true;
            x *= -1;
        }
        long long n = 0;
        while (x) {
            n = n*10 + x%10;
            x /= 10;
        }
        if (n>INT_MAX) return 0;
        if (n<INT_MIN) return 0;
        return nflag?-1*n:n;
        
    }
};

int main() {
    Solution s;
    int x,y;
    x = 123;
    y = 321;
    printf("%s\n",s.reverse(x)==y?"true":"false");
    x = -123;
    y = -321;
    printf("%s\n",s.reverse(x)==y?"true":"false");
    x = 120;
    y = 21;
    printf("%s\n",s.reverse(x)==y?"true":"false");
    x = 1534236469;
    y = 0;
    printf("%s\n",s.reverse(x)==y?"true":"false");
}