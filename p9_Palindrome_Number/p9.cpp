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
        int ox = x;
        int n = 0;
        while (x) {
            n = n*10 + x%10;
            x /= 10;
        }
        return n==ox;

    }
};

int main() {
    Solution s;
    for (int i = 0; i < 200; i++) {
        printf("%d %s\n",i,s.isPalindrome(i)?"true":"false");
    }
}