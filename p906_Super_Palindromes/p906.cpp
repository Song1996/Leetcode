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
    long long intrev(long long x) {
        long long ans = 0;
        while(x) {
            ans *= 10; ans += x%10; x /= 10;
        }
        return ans;
    }
    int superpalindromesInRange(string L, string R) {
        //L,R<10^18 -> R<10^9 -> hR < 10^4
        long long Ln = 0; for(int i = 0; i < L.length(); i++) {Ln*=10; Ln+=(L[i]-'0');}
        long long Rn = 0; for(int i = 0; i < R.length(); i++) {Rn*=10; Rn+=(R[i]-'0');}
        //printf("%lld %lld\n",Ln,Rn);
        long long root; long long n; int ans = 0;
        for(int hr = 1; hr < 10000; hr++) {
            int k = 1; int t = hr; while(t) {k*=10; t/=10;}
            root = hr*k+intrev(hr); 
            n = root*root; 
            if(n>=Ln && n<=Rn&& n==intrev(n)) {ans++;}
        }
        for(int i = 0; i < 10; i++) {
            root = i;
            n = root*root; 
            if(n>=Ln && n<=Rn && n==intrev(n)) {
                ans++;
            }
            for(int hr = 1; hr < 10000; hr++) {
                int k = 1; int t = hr; while(t) {k*=10; t/=10;}
                root = i*k + hr*k*10 +intrev(hr); 
                n = root*root; 
                if(n>=Ln && n<=Rn&& n==intrev(n)) {ans++;}
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    //for(int i = 100; i < 200; i++) printf("%d %d\n",i,s.intrev(i));
    printf("%d\n",s.superpalindromesInRange("398904669","13479046850"));
    return 0;
}