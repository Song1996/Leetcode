#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <cassert>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int num = 0;
        int sign = 1;
        int ans = 0;
        stack<int> nums;
        stack<int> ops;
        for (char c:s) {
            if(isdigit(c)) {
                num *= 10; num += c - '0';
            } else if(c=='+') {
                ans += sign * num;
                sign = 1; num = 0;
            } else if(c=='-') {
                ans += sign * num;
                sign = -1; num = 0;
            } else if(c=='(') {
                nums.push(ans);
                ops.push(sign);
                ans = 0; sign = 1;
            } else if(c==')') {
                ans += sign * num;
                num = ans;
                sign = ops.top();
                ans = nums.top();
                nums.pop(); ops.pop();
            }
        }
        ans += sign*num;
        return ans;
    }
};

int main() {
    Solution s; string x;
    x = "1 + 1";
    printf("%s = %d\n",x.c_str(),s.calculate(x));
    x = " 2-1 + 2 ";
    printf("%s = %d\n",x.c_str(),s.calculate(x));
    x = "(1+(4+5+2)-3)+(6+8)";
    printf("%s = %d\n",x.c_str(),s.calculate(x));
    x = "1-(5)";
    printf("%s = %d\n",x.c_str(),s.calculate(x));
    x = "1-((5))";
    printf("%s = %d\n",x.c_str(),s.calculate(x));
    return 0;
}