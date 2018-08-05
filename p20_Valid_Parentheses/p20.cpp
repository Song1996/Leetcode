#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<int> mem;
        for (int i = 0; i < s.length(); i ++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') mem.push(s[i]);
            else if ( mem.size() == 0 ) return false;
            else if (   (s[i]==')' && mem.top()=='(') || 
                        (s[i]=='}' && mem.top()=='{') || 
                        (s[i]==']' && mem.top()=='[') ) 
                        mem.pop();
            else return false;
        }
        if (mem.size()>0) return false;
        else return true;
    }
};

int main () {
    string x;
    bool y;
    Solution s;
    x = "()";
    y = true;
    printf("%s\n",s.isValid(x)==y?"true":"false");
    x = "()[]{}";
    y = true;
    printf("%s\n",s.isValid(x)==y?"true":"false");
    x = "(]";
    y = false;
    printf("%s\n",s.isValid(x)==y?"true":"false");
    x = "([)]";
    y = false;
    printf("%s\n",s.isValid(x)==y?"true":"false");
    x = "{[]}";
    y = true;
    printf("%s\n",s.isValid(x)==y?"true":"false");
}
