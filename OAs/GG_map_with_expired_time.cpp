#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <cassert>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;

class myMap{
    map<int, pair<int, unsigned int>> M;
    myMap() {
        M.clear();
    }
    void put(int key, int value, unsigned int expire_time, unsigned int cur_time) {
        pair<int, unsigned int> p(value, expire_time + cur_time);
        M[key] = p;
    }
    int get(int key, unsigned int cur_time) {
        if(M.find(key)==M.end()) return NULL;
        if(cur_time <= M[key].second) return M[key].first;
        return NULL;
    }
    void clean_up(unsigned int cur_time) {
        auto p = M.begin();
        while(p != M.end()) {
            if(p->second.second > cur_time) p = M.erase(p);
            else p++;
        }
    }
};

int main() {

    return 0;
}