#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <cassert>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans(max(num1.length(), num2.length()),'0');
        int carry, n1, n2, pos, t;
        carry = 0, pos = 0;
        while(pos<ans.length()) {
            n1 = pos<num1.length()?num1[num1.length()-1-pos]-'0':0;
            n2 = pos<num2.length()?num2[num2.length()-1-pos]-'0':0;
            t = n1 + n2 + carry;
            ans[ans.length()-1-pos] = t%10 + '0';
            carry = t/10;
            pos++;
        }
        if(carry>0) ans = string(1,carry+'0') + ans;
        return ans;
    }
};

int main () {
    string num1, num2;
    Solution s;
    num1 = "312", num2 = "123";
    printf("%s + %s %s %d\n",num1.c_str(), num2.c_str(), s.addStrings(num1, num2).c_str(), stoi(num1)+stoi(num2));
	return 0;
}