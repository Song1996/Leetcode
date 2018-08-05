#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) {
            return false;
        }else if (x==0) {
            return true;
        }
        int l = 0;
        while (x > 0) {
            n[l] = x%10;
            x /= 10;
            l ++;
        }
        for (int i = 0; i < l/2; i++) {
            if (n[i] != n[l-i-1]) return false;
        }
        return true;

    }
private:
    int n[32];
};

int main() {
    Solution s;
    for (int i = 0; i < 200; i++) {
        printf("%d %s\n",i,s.isPalindrome(i)?"true":"false");
    }
}