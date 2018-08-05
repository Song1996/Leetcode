#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p[0]=='*') {
            printf("error\n");
            return false;
        }
        int pl = p.length();
        int sl = s.length();
        if (pl==0){
            return sl==0;
        }else if(pl==1){
            if (p[0]=='.') return sl==1;
            else if (sl==1) return s[0]==p[0];
            else return false;
        } else if (p[1]=='*' and p[0]=='.') {
            for (int i = 0;i<=sl;i++) {
                if (isMatch(s.substr(i,sl-i),p.substr(2,pl-2)))
                    return true;
            }
            return false; 
        } else if (p[1]=='*' and p[0]!='.') {
            if (isMatch(s,p.substr(2,pl-2)))
                return true;
            int i = 1;
            while (i <= sl && s[i-1]==p[0]) {
                if (isMatch(s.substr(i,sl-i),p.substr(2,pl-2)))
                    return true;
                i++;
            }
            return false;
        }else if (sl==0){
            return false;
        } else if (p[0]=='.') {
            return isMatch(s.substr(1,sl-1),p.substr(1,pl-1));
        } else if (s[0]==p[0]){
            return isMatch(s.substr(1,sl-1),p.substr(1,pl-1));
        }else return false;
    }
};

int main() {
    Solution solution;
    string s,p;
    bool answer;
    s = "aa";
    p = "a";
    answer = false;
    printf("%s\n",solution.isMatch(s,p) == answer?"true":"false");
    s = "aa";
    p = "a*";
    answer = true;
    printf("%s\n",solution.isMatch(s,p) == answer?"true":"false");
    s = "ab";
    p = ".*";
    answer = true;
    printf("%s\n",solution.isMatch(s,p) == answer?"true":"false");
    s = "aab";
    p = "c*a*b";
    answer = true;
    printf("%s\n",solution.isMatch(s,p) == answer?"true":"false");
    s = "mississippi";
    p = "mis*is*p*.";
    answer = false;
    printf("%s\n",solution.isMatch(s,p) == answer?"true":"false");
    s = "a";
    p = ".*..a*";
    answer = false;
    printf("%s\n",solution.isMatch(s,p) == answer?"true":"false");
}