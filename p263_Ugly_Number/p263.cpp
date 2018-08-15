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
    bool isUgly(int n) {
        if (n<1) return false;
        if (n==1) return true;
        if(n%2==0) return isUgly(n/2);
        if(n%3==0) return isUgly(n/3);
        if(n%5==0) return isUgly(n/5);
        return false;
    }
};

int main () {
    Solution s;
    printf("%s\n", s.isUgly(6)?"true":"false");
    printf("%s\n", s.isUgly(8)?"true":"false");
    printf("%s\n", s.isUgly(14)?"true":"false");
	return 0;
}
