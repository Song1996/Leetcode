#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <cassert>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int p = 0; map<int, int> d;
        for(int i = 0; i < S.length();) {
            char c = S[i]; int n = 1;
            while(++i < S.length() && S[i]==c) n++;
            d[p] = n;
            S[p++] = c;
        }
        S = S.substr(0,p);
        int ans = 0;
        for(string w:words) if(helper(S,d,w)) ans++;
        return ans;
    }
    bool helper(string s, map<int, int> d, string t) {
        int p0 = 0, p1 = 0;
        //printf("%s\n",t.c_str());
        while(p0 < s.length()) {
            char c = s[p0];
            //printf("%c %d ",c,d[p0]);
            if(p1>=t.length() || t[p1]!=c) return false;
            int n = 1; while(++p1 < t.length() && t[p1]==c) n++;
            //printf("%d\n",n);
            if(n>d[p0] || (n<d[p0] && d[p0]<3)) return false;
            p0++;
        }
        return true;
    }
};

int main() {
    Solution s;
    string x[] = {"hello", "hi", "helo"};
    vector<string> v(x,x+sizeof(x)/sizeof(string));
    printf("%d\n",s.expressiveWords("heeellooo",v));
    return 0;
}