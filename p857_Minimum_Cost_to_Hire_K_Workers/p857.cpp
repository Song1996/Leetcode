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
    static bool my_compare(pair<double,double> x, pair<double,double> y) {
        return x.first < y.first;
    }
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        vector<pair<double,double> > mem;
        for(int i = 0; i < quality.size(); i++) {
            mem.push_back(pair<double,double>(1.0*wage[i]/quality[i],1.0*quality[i]));
        }
        sort(mem.begin(),mem.end(),my_compare);
        double ans = std::numeric_limits<double>::max();
        priority_queue<double> pq;
        double qsum = 0;
        for(int i = 0; i < mem.size(); i++) {
            qsum += mem[i].second;
            if(pq.size()==K-1) {
                pq.push(mem[i].second);
                ans = min(ans, qsum*mem[i].first);
            } else if(pq.size()==K) {
                qsum -= pq.top(); pq.pop(); pq.push(mem[i].second);
                ans = min(ans, qsum * mem[i].first);
            } else pq.push(mem[i].second);
        }
        return ans;
    }
};

int main() {
    return 0;
}