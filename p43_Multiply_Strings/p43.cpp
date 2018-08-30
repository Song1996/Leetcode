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
    string multiply(string num1, string num2) {
        if(num1[0]=='0' || num2[0]=='0') return "0";
        string ans = "0";
        string tans;
        int pos, carry, ca, ct, factor, t;
        for(int i = 0; i < num2.size(); i++) {
            tans = num1+string(i,'0');
            factor = num2[num2.size()-i-1]-'0';
            if(factor==0) continue;
            else {
                carry = 0;
                for(int j = tans.size()-1-i; j >= 0; j--) {
                    t = factor * (tans[j] - '0') + carry;
                    tans[j] = t%10 + '0';
                    carry = t/10;
                }
                if(carry>0) tans = string(1,carry+'0') + tans;
            }
            pos = 0, carry = 0;
            while(pos<ans.length() || pos<tans.length()) {
                ca = pos<ans.length()?(ans[ans.length()-pos-1]-'0'):0;
                ct = pos<tans.length()?(tans[tans.length()-pos-1]-'0'):0;
                t = ca+ct+carry;
                if(pos<ans.length()) ans[ans.length()-pos-1] = t%10+'0';
                else ans = string(1,t%10+'0') + ans;
                carry = t/10;
                if(carry == 0 && pos>=tans.length()) break;
                pos++;
            }
            if(carry>0) ans = string(1,carry+'0') + ans;
        }
        return ans;
    }
};

int main () {
    string num1, num2;
    Solution s;
    num1 = "4321", num2 = "1234";
    printf("%s x %s = %s %d\n", num1.c_str(), num2.c_str(), s.multiply(num1, num2).c_str(), atoi(num1.c_str())*atoi(num2.c_str()));
    num1 = "123", num2 = "456";
    printf("%s x %s = %s\n", num1.c_str(), num2.c_str(), s.multiply(num1, num2).c_str());
        num1 = "123", num2 = "0";
    printf("%s x %s = %s\n", num1.c_str(), num2.c_str(), s.multiply(num1, num2).c_str());
	return 0;
}