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
    vector<vector<int> > dict;
    bool isMatch(string s, string p) {
        dict.clear(); dict.resize(s.length()+1);
        for(int i = 0; i < s.length()+1; i++) dict[i].resize(p.length()+1);
        /*printf("%s %s\n",s.c_str(),p.c_str());
        for(int i = 0; i < dict.size(); i++){
            for(int j = 0; j < dict[i].size(); j++)
                printf("%d ",dict[i][j]);
            printf("\n");
        }
        printf("entered\n");*/
        return myMatch(0,0,s.length(),p.length(),s,p)==1;
    }
    int myMatch(int x, int y, int lx, int ly, string& s, string& p) {
        pair<int, int> index; index.first = x; index.second = y;
        if(dict[x][y] != 0) return dict[x][y];
        if(x == lx && y == ly) dict[x][y] = 1;
        else if(x == lx) {
            if(p[y]!='*') dict[x][y] = 2;
            else dict[x][y] = myMatch(x, y+1, lx, ly, s, p);
        }
        else if(y == ly) dict[x][y] = 2;
        else if(p[y]=='?') dict[x][y] = myMatch(x+1, y+1, lx, ly, s, p);
        else if(p[y]!='*') {
            if(p[y]==s[x]) dict[x][y] = myMatch(x+1, y+1, lx, ly, s, p);
            else dict[x][y]= 2;
        }
        else {
            if(myMatch(x, y+1, lx, ly, s, p)==1) dict[x][y] = 1;
            for(int i = 1; x+i <= s.length(); i++){
                if(myMatch(x+i, y+1, lx, ly, s, p)==1) dict[x][y] = 1;
            }
        }
        if(dict[x][y]==0) dict[x][y] = 2;
        return dict[x][y];
    }
};

int main () {
    Solution sol;
    string s; string p;
    s = "aa"; p = "a";
    printf("%s %s %s\n", s.c_str(), p.c_str(), sol.isMatch(s, p)?"true":"false");
    s = "aa"; p = "*";
    printf("%s %s %s\n", s.c_str(), p.c_str(), sol.isMatch(s, p)?"true":"false");
    s = "cb"; p = "?a";
    printf("%s %s %s\n", s.c_str(), p.c_str(), sol.isMatch(s, p)?"true":"false");
    s = "adceb"; p = "*a*b";
    printf("%s %s %s\n", s.c_str(), p.c_str(), sol.isMatch(s, p)?"true":"false");            
    s = "acdcb"; p = "a*c?b";
    printf("%s %s %s\n", s.c_str(), p.c_str(), sol.isMatch(s, p)?"true":"false");            
    return 0;
}