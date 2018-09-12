#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <cassert>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& cits) {
        if(cits.size()==0) return 0;
        sort(begin(cits), end(cits));
        for(int i = 1; i <= cits.size(); i++) {
            
        }
        return 0;
    }
};

int main() {
    Solution s;
    int xlist[] = {1,1};//{3,0,6,1,5};
    vector<int> x(xlist, xlist+2);
    printf("%d\n",s.hIndex(x));
    return 0;
}