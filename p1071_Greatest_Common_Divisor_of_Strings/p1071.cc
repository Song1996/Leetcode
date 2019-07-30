#include<string>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1.length() == 0) return str2;
        if(str2.length() == 0) return str1;
        string longStr, shortStr;
        if(str1.length() < str2.length()) {
            longStr = str2;
            shortStr = str1;
        } else {
            longStr = str1;
            shortStr = str2;
        }
        if(longStr.substr(0, shortStr.length()) != shortStr) return string("");
        while(longStr.substr(0, shortStr.length()) == shortStr) {
            longStr = longStr.substr(shortStr.length());
        }
        return gcdOfStrings(longStr, shortStr);
    }
};