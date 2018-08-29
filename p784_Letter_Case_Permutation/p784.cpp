#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <assert.h>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        int pos = 0;
        dfs(ans, S, 0);
        return ans;
    }
    void dfs(vector<string>& ans, string& S, int pos) {
        while(pos<S.size()) {
            if((S[pos]<='z' && S[pos]>='a') || (S[pos]<='Z' && S[pos]>='A')) break;
            pos++;
        }
        if(pos==S.size()) {
            ans.push_back(S);
            return;
        }
        dfs(ans, S, pos+1);
        if(S[pos]<='Z'&&S[pos]>='A'){
            S[pos] -= ('A' - 'a');
            dfs(ans, S, pos+1);
            S[pos] += ('A' - 'a');
        } else {
            S[pos] += ('A' - 'a');
            dfs(ans, S, pos+1);
            S[pos] -= ('A' - 'a');
        }
        return;
    }
};

int main () {
    Solution s;
    string x;
    vector<string> y;
    x = "C"; printf("%s\n",x.c_str());
    y = s.letterCasePermutation(x);
    for(int i = 0; i < y.size(); i++) printf("%s ",y[i].c_str()); printf("\n");
    x = "3z4"; printf("%s\n",x.c_str());
    y = s.letterCasePermutation(x);
    for(int i = 0; i < y.size(); i++) printf("%s ",y[i].c_str()); printf("\n");
    x = "12345"; printf("%s\n",x.c_str());
    y = s.letterCasePermutation(x);
    for(int i = 0; i < y.size(); i++) printf("%s ",y[i].c_str()); printf("\n");
	return 0;
}