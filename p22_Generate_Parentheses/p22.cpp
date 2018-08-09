#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s = "";
        dfs(result,"",n,0);
        return result;
    }
private:
    void dfs(vector<string>& result, string s, int n, int m) {
        if(n==0&&m==0) {
            result.push_back(s);
            return;
        }
        if(n>0) dfs(result,s+"(",n-1, m+1);
        if(m>0) dfs(result,s+")",n  , m-1);
        return;
    }
};

int main () {
    int n = 3;
    Solution s;
    vector<string> result = s.generateParenthesis(n);
    for (vector<string>:: iterator it = result.begin(); it != result.end(); it ++) {
        printf("%s\n",(*it).c_str());
    }
}