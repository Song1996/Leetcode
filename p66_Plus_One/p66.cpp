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
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans(digits.begin(), digits.end());
        int carry = 1;
        for(int i = digits.size()-1; i >= 0; i--) {
            if(carry==0) ans[i] = digits[i];
            else if(digits[i]==9) ans[i] = 0;
            else {
                ans[i] = digits[i]+1;
                carry = 0;
                break;
            }
        }
        if(carry==1) ans.insert(ans.begin(), 1);
        return ans;
    }
};

int main () {
    int x1[] = {9,9,9};
    vector<int> v1(x1, x1+3);
    int x2[] = {4,3,2,1};
    vector<int> v2(x2, x2+4);
    Solution s;
    for(int i = 0; i < v1.size(); i++) printf("%d ",v1[i]); printf("\n");
    vector<int> y = s.plusOne(v1);
    for(int i = 0; i < y.size(); i++) printf("%d ",y[i]); printf("\n");
    for(int i = 0; i < v2.size(); i++) printf("%d ",v2[i]); printf("\n");
    y = s.plusOne(v2);
    for(int i = 0; i < y.size(); i++) printf("%d ",y[i]); printf("\n");
	return 0;
}