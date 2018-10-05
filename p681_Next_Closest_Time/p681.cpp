#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <cassert>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    void dfs(int depth,const string& dict, string mem, int now, int& min_dist, string& ans) {
        if(depth==4) {
            int hour = atoi(mem.substr(0,2).c_str());
            if(hour>23) return;
            int minute = atoi(mem.substr(2,2).c_str());
            if(minute>59) return;
            int t = hour*60 + minute;
            int dist = t - now;
            if(dist<=0) dist += 24*60;
            //printf("%s %d\n",mem.c_str(),dist);
            if(dist<min_dist) {
                min_dist = dist;
                ans = mem.substr(0,2) + ":" + mem.substr(2,2);
            }
            return;
        }
        for(char c:dict) {
            mem.push_back(c);
            dfs(depth+1,dict,mem,now,min_dist,ans);
            mem.pop_back();
        }
        return;
    }
    string nextClosestTime(string time) {
        string dict;
        for(char i:time) {
            if(i==':') continue;
            for(char j:dict) if(i==j) continue;
            dict.push_back(i);
        }
        int min_dist = INT_MAX;
        string ans = "";
        int now = atoi(time.substr(0,2).c_str())*60 + atoi(time.substr(3,2).c_str());
        dfs(0,dict,"",now,min_dist,ans);
        return ans;
    }
};

int main() {
    return 0;
}