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

bool cmp(const string& s1, const string& s2) {
    return s1+s2>s2+s1;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> ss;
        for(int i = 0; i < nums.size(); i++) ss.push_back(to_string(nums[i]));
        sort(ss.begin(), ss.end(), cmp);
        string ans;
        for(int i = 0; i < ss.size(); i++){
            ans += ss[i];
        }
        while(ans[0]=='0'&&ans.length()>1) ans.erase(0,1);
        return ans;
    }
};

int main () {
    vector<int> x;
    x.push_back(0); x.push_back(0);
    //x.push_back(3); x.push_back(30); x.push_back(34); x.push_back(5); x.push_back(9);
    Solution s;
    printf("%s\n",s.largestNumber(x).c_str());
	return 0;
}