#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int l1 = 0;
        while(l1<version1.length()) {
            if(version1[l1++]=='.') break;
        }
        int v1;
        v1 = l1>0?atoi(version1.substr(0,l1).c_str()):0;
        //version1 = version1.substr(l1,version1.size()-l1);
        int l2 = 0;
        while(l2<version2.length()) {
            if(version2[l2++]=='.') break;
        }
        int v2;
        v2 = l2>0?atoi(version2.substr(0,l2).c_str()):0;
        //version2 = version2.substr(l2,version2.size()-l2);
        if(l1==0 && l2==0) return 0;
        else if(v1==v2) return compareVersion(version1.substr(l1,version1.length()-l1), version2.substr(l2, version2.length()-l2));
        else if(v1<v2) return -1;
        else return 1;

    }
};

int main() {
    string s1 = "7.5.2.4";
    string s2 = "7.5.3";
    Solution s;
    printf("%d\n",s.compareVersion(s1, s2));
}