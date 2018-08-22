#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <assert.h>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
using namespace std;

struct mypair {
    int x, y; 
    mypair(int t1, int t2){x=t1;y=t2;}
    bool operator < (const mypair& other) const{
        return (x<other.x || (x==other.x&&y<other.y));
    }
};

class Solution {
public:
    string fractionToDecimal(long long numerator, long long denominator) {
        string ans = "";
        if( (numerator>0&&denominator<0) || (numerator<0&&denominator>0) ) ans += string("-");
        numerator = abs(numerator); denominator = abs(denominator);
        ans += to_string(numerator/denominator);
        numerator %= denominator;
        map<mypair, int> M;
        if(numerator>0) ans += ".";
        int d = ans.length();
        while(numerator>0) {
            //printf("%d %d %d\n",d,numerator,denominator);
            mypair t(numerator,denominator);
            //printf("%d %d\n",t.x,t.y);
            if(M.find(t)!=M.end()) {
                //printf("%s %d %d\n",ans.c_str(),M[t],ans.length());
                string p1 = ans.substr(0,M[t]);
                string p2 = ans.substr(M[t],ans.length());
                //printf("%s\n%s\n%s\n",p1.c_str(),p2.c_str(),(p1+p2).c_str());
                ans = p1+"("+p2+")";
                break;
            }
            M[t] = d++;
            numerator*=10;
            ans += to_string((numerator/denominator)%10);
            numerator %= denominator;
        }
        return ans;
    }
};

int main () {
    Solution s;
    printf("%s\n",s.fractionToDecimal(-1,INT_MIN).c_str());
	return 0;
}