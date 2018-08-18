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
    int ans;
    int mem[2048];
    bool Mypalindrom(string s) {
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
    int minCut(string& s) {
        ans = INT_MAX;
        if(s.length()==0) return 0;
        if(s.length()>2048) return 0;
        memset(mem, -1, sizeof(mem));
        for(int i = 0; i < s.length(); i++) {
            if(Mypalindrom(s.substr(i,s.length()-i))) mem[i] = 0;
        }
        return dp(s, 0);
    }
    int dp(string& s, int n) {
        if(mem[n]!=-1) return mem[n];
        int ans = -2;
        for(int l = 1; l < s.length()-n; l++) {
            if(Mypalindrom(s.substr(n,l)) && dp(s, n+l)>=0) {
                if(ans==-2) ans = dp(s, n+l)+1;
                else if(dp(s, n+l)+1<ans) ans = dp(s, n+l)+1;
            }
        }
        mem[n] = ans;
        return ans;
    }
};

int main () {
    string x = "abc";
    Solution s;
    printf("%d\n", s.minCut(x));
	return 0;
}