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
    string minWindow(string s, string t) {
        int p1, p2;
        int memt[256]; int mems[256];
        memset(memt,0,sizeof(memt));
        memset(mems,0,sizeof(mems));
        int num_no_zero = 0;
        for(int i = 0; i < t.length(); i++) {
            if(memt[t[i]]++==0) num_no_zero++;
        }
        int min_len = INT_MAX; 
        string ans = "";
        p1 = 0; p2 = 0;
        while(p2 < s.length()) {
            if(memt[s[p2]] && ++mems[s[p2]]==memt[s[p2]] && !--num_no_zero) {
                min_len = ++p2 - p1;
                ans = s.substr(p1,p2-p1);
                break;
            }
            p2++;
        }
        if(num_no_zero) return ans;
        //printf("%s\n",ans.c_str());
        while(p1<s.length()) {
            while(p1<p2) {
                if(memt[s[p1++]] && mems[s[p1-1]]--==memt[s[p1-1]] && ++num_no_zero) break;
                if(!num_no_zero && p2-p1<min_len) {
                    //printf("here1 ");
                    min_len = p2 - p1;
                    ans = s.substr(p1,p2-p1);
                    //printf("%s\n",ans.c_str());
                }
            }
            //printf("%d %s %s\n",num_no_zero,ans.c_str(),s.substr(p1,s.length()-p1).c_str());
            while(p2<s.length()) {
                if(memt[s[p2]] && ++mems[s[p2]]==memt[s[p2]] && !--num_no_zero) {
                    //printf("here2 ");
                    if(++p2 - p1 < min_len) {
                        min_len = p2 - p1;
                        ans = s.substr(p1,p2-p1);
                    }
                    //printf("%s\n",ans.c_str());
                    break;
                }
                p2++;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    string x1, x2, y;
    x1 = "ADOBECODEBANC", x2 = "ABC";
    //x1 = "A", x2 = "AA";
    //x1 = "AB", x2 = "B";
    x1 = "cabwefgewcwaefgcf", x2 = "cae";
    y = s.minWindow(x1,x2);
    printf("%s\n",y.c_str());
    return 0;
}