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
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> mem;
    bool checkInclusion(string s1, string s2) {
        int l = s1.length();
        if(s2.length()<l) return false;
        mem.clear(); mem.resize(26,0);
        for(int i = 0; i < l; i++) mem[s1[i]-'a']++;
        for(int i = 0; i < l; i++) mem[s2[i]-'a']--;
        int n = 0;
        for(int i = 0; i < 26; i++) if(mem[i]!=0) n++;
        if(n==0) return true;
        for(int i = l; i < s2.length(); i++) {
            if(s2[i-l]==s2[i]) continue;
            mem[s2[i-l]-'a']++; mem[s2[i]-'a']--;
            if(mem[s2[i-l]-'a']==0) n--;
            else if(mem[s2[i-l]-'a']==1) n++;
            if(mem[s2[i]-'a']==0) n--;
            else if(mem[s2[i]-'a']==-1) n++;
            if(n==0) return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    string s1, s2;
    s1 = "ab", s2 = "eidbaooo";
    printf("%s\n",s.checkInclusion(s1,s2)?"true":"false");
    s1= "ab", s2 = "eidboaoo";
    printf("%s\n",s.checkInclusion(s1,s2)?"true":"false");
    s1 = "trinitrophenylmethylnitramine";
    s2 = "dinitrophenylhydrazinetrinitrophenylmethylnitramine";
    //s2 = "trinitrophenylmethylnitramine";
    printf("%s\n",s.checkInclusion(s1,s2)?"true":"false");
    return 0;
}