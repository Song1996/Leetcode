#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <cassert>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if(s.length()<=2) return s.length();
        map<char,int> mem; mem.clear(); mem[s[0]] = 1;
        int lp = 0;
        int p = 1;
        int ans = 0;
        while(p < s.length()) {
            if(s[p++]==s[0]) mem[s[0]]++;
            else break;
        }
        if(p==s.length()) return s.length();
        else mem[s[p-1]] = 1;
        while(p < s.length()) {
            if(mem.find(s[p])!=mem.end()) {
                mem[s[p]]++;
            } else {
                ans = max(ans, p - lp);
                while(lp < p) {
                    mem[s[lp]]--;
                    if(mem[s[lp]]==0) {
                        mem.erase(s[lp]);
                        mem[s[p]] = 1;
                        lp++;
                        break;
                    }
                    lp++;
                }
            }
            p++;
        }
        ans = max(ans, p - lp);
        return ans;
    }
};

int main() {
    return 0;
}