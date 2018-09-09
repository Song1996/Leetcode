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
    vector<int> diffWaysToCompute(string input) {
        vector<int> ans;
        vector<int> n;
        vector<char> op;
        int i = 0, p = 0;
        while(i<input.length() && input[i]<='9' && input[i]>='0') i++;
        if(i==input.length()) {
            ans.push_back(atoi(input.c_str()));
            return ans;
        }
        n.push_back(atoi(input.substr(p,i-p).c_str()));
        op.push_back(input[i]);
        p = i+1; i++;
        while(i<input.size()) {
            if(input[i]<='9' && input[i]>='0') i++;
            else {
                n.push_back(atoi(input.substr(p,i-p).c_str()));
                op.push_back(input[i]);
                p = i+1;
                i++;
            }
        }
        n.push_back(atoi(input.substr(p,i-p).c_str()));
        //for(int i = 0; i < n.size(); i++) printf("%d ",n[i]); printf("\n");
        //for(int i = 0; i < op.size(); i++) printf("%c ",op[i]); printf("\n");
        return helper(n, op, 0, n.size(), 0, op.size());
    }
    vector<int> helper(vector<int>& n, vector<char>& op, int ns, int ne, int ops, int ope) {
        vector<int> ans;
        if(ne==ns+1) {
            ans.push_back(n[ns]); return ans;
        }
        for(int i = ops; i < ope; i++) {
            char myop = op[i];
            vector<int> lans = helper(n, op, ns, i+1, ops, i);
            vector<int> rans = helper(n, op, i+1, ne, i+1, ope);
            for(int j = 0; j < lans.size(); j++) {
                for(int k = 0; k < rans.size(); k++) {
                    if(myop=='+') ans.push_back(lans[j]+rans[k]);
                    else if(myop=='-') ans.push_back(lans[j]-rans[k]);
                    else if(myop=='*') ans.push_back(lans[j]*rans[k]);
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    string x;
    vector<int> y;
    x = "2-1-1";
    y = s.diffWaysToCompute(x);
    printf("%s\n",x.c_str());
    for(int i = 0; i < y.size(); i++) printf("%d ",y[i]); printf("\n");
    x = "2*3-4*5";
    y = s.diffWaysToCompute(x);
    printf("%s\n",x.c_str());
    for(int i = 0; i < y.size(); i++) printf("%d ",y[i]); printf("\n");
    return 0;
}