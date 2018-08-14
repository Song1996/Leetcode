#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <string>
#include <assert.h>
#include <algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        for(vector<Interval>::iterator it = intervals.begin(); it!=intervals.end(); it++){
            printf("(%2d, %2d), ",it->start,it->end);
        }printf("\n");
        
        vector<Interval> ans;
        map<int,int> d;
        for(vector<Interval>::iterator it = intervals.begin(); it!=intervals.end(); it++){
            if(d.find(it->start)==d.end()) d[it->start] = 1;
            else d[it->start]++;
            if(d.find(it->end)==d.end()) d[it->end] = -1;
            else d[it->end]--;
        }
        int cur_state = 0;
        int last_pos = -1;
        bool no_last_pos = true;
        for(map<int,int>::iterator it = d.begin(); it!=d.end(); it++){
            //printf("%2d->%2d\n",it->first,it->second);
            if(it->second==0) {
                if (no_last_pos) {
                    ans.push_back(*(new Interval(it->first,it->first)));
                }
            }else if(it->second>0 && no_last_pos) {
                cur_state += it->second;
                last_pos = it->first;
                no_last_pos = false;
            }else if(it->second>0 && !no_last_pos) {
                cur_state += it->second;
            }else{ //it->second<0
                cur_state += it->second;
                if(cur_state<0) assert(0);
                else if(cur_state==0) {
                    ans.push_back(*(new Interval(last_pos, it->first)));
                    no_last_pos = true;
                }
            }
        }
        return ans;
    }
};

int main () {
    vector<Interval> x;
    x.push_back(*(new Interval(1,3)));
    x.push_back(*(new Interval(2,6)));
    x.push_back(*(new Interval(8,10)));
    x.push_back(*(new Interval(15,18)));
    x.push_back(*(new Interval(2,2)));
    //x.push_back(*(new Interval(1,4)));
    x.push_back(*(new Interval(-1,-1)));
    //x.push_back(*(new Interval(4,5)));
    Solution s;
    vector<Interval> y = s.merge(x);
    for(vector<Interval>::iterator it = y.begin(); it!=y.end(); it++){
        printf("(%2d, %2d), ",it->start,it->end);
    }printf("\n");
	return 0;
}
