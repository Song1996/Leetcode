#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <assert.h>
#include <algorithm>
using namespace std;

#define String_Hash_Seed 100000007
typedef unsigned long long ull;

class Solution {
public:
    vector<vector<string> > ans;
    vector<string> mem;
    bool Mypalindrom(string& s) {
        int l = 0;
        int r = s.length()-1;
        while(l<r) {
            if(s[l]==s[r]){
                l++;
                r--;
            }else return false;
        }
        return true;
    }

    vector<vector<string> > partition(string& s) {
        if(s.length()==0) return ans;
        dfs(s, 0);
        return ans;
    }
    void dfs(string& s, int pos) {
        if(pos==s.length()) {
            ans.push_back(mem);
            return;
        }
        for(int l = 1; l <= s.length()-pos; l++) {
            string t = s.substr(pos,l);
            if(Mypalindrom(t)) {
                mem.push_back(t);
                dfs(s, pos+l);
                mem.pop_back();
            }
        }
        return;
    }
};

int main () {
    string x = "aab";
    Solution s;
    vector<vector<string> > y = s.partition(x);
    for(int i = 0; i < y.size(); i++) {
        for(int j = 0; j < y[i].size(); j++) {
            printf("%s, ",y[i][j].c_str());
        }printf("\n");
    }
	return 0;
}