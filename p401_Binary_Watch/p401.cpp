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
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        vector<int> hours;
        vector<int> minutes;
        string t = ":00";
        int mem = 0;
        for(int i = 0; i <= num; i++) {
            hours.clear(); mem = 0; dfs(hours, 4, i, mem);
            minutes.clear(); mem = 0; dfs(minutes, 6, num-i, mem);
            for(int j = 0; j < hours.size(); j++) {
                if(hours[j] > 11) continue;
                for(int k = 0; k < minutes.size(); k++) {
                    if(minutes[k] > 59) continue;
                    t[2] = minutes[k]%10 + '0';
                    t[1] = minutes[k]/10 + '0';
                    ans.push_back(to_string(hours[j])+t);
                }
            }
        }
        return ans;
    }
    void dfs(vector<int>& hours, int pos, int left, int& mem) {
        if(left > pos+1) return;
        if(pos == 0 && left == 0) {
            hours.push_back(mem);
            return;
        }
        if(left < pos) dfs(hours, pos-1, left, mem);
        if(left > 0){
            mem ^= (1<<(pos-1));
            dfs(hours, pos-1, left-1, mem);
            mem ^= (1<<(pos-1));
        }
    }
};

int main () {
    Solution s;
    vector<string> y = s.readBinaryWatch(1);
    for(int i = 0; i < y.size(); i++) {
        printf("%s\n",y[i].c_str());
    }
	return 0;
}