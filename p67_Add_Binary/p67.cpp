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
    string addBinary(string a, string b) {
        //if(a.length()<b.length()) swap(a,b);
        //printf("%s %s\n",a.c_str(),b.c_str());
        string ans(max(a.length(),b.length())+1,'0');
        int pos = 0; bool flag = false;
        char ca,cb;
        while(pos<ans.length()) {
            ca = pos<a.length()?a[a.length()-1-pos]:'0';
            cb = pos<b.length()?b[b.length()-1-pos]:'0';
            if(ca=='0'&&cb=='0') {
                ans[ans.length()-pos-1] = flag?'1':'0';
                flag = false;
            } else if((ca=='1'&&cb=='0') || (ca=='0'&&cb=='1')) {
                //printf("%d\n",pos);
                ans[ans.length()-pos-1] = flag?'0':'1';
            } else {
                ans[ans.length()-pos-1] = flag?'1':'0'; 
                flag = true;
            }
            pos++;
        }
        //printf("%s\n",ans.c_str());
        return ans[0]=='0'?ans.substr(1,ans.length()-1):ans;
    }
};

int main () {
    string a, b;
    Solution s;
    a = "1"; b = "11";
    printf("%s + %s = %s\n",a.c_str(),b.c_str(),s.addBinary(a,b).c_str());
    a = "1010"; b = "1011";
    printf("%s + %s = %s\n",a.c_str(),b.c_str(),s.addBinary(a,b).c_str());
	return 0;
}