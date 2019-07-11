#include<queue>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    typedef priority_queue<int, vector<int>, greater<int> > heap;
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, heap> mem;
        for(int i = 0; i < items.size(); i++) {
            if(mem.find(items[i][0]) == mem.end() ) mem[items[i][0]] = heap();
            mem[items[i][0]].push(items[i][1]);
            if(mem[items[i][0]].size() == 6) mem[items[i][0]].pop();
        }
        vector< vector<int> > ans;
        for(auto it:mem) {
            vector<int> t_vec;
            t_vec.push_back(it.first);
            int sum = 0;
            for(int i = 0; i < 5; i++) {
                sum += it.second.top();
                it.second.pop();
            }
            t_vec.push_back(sum/5);
            ans.push_back(t_vec);
        }
        return ans;
    }
};