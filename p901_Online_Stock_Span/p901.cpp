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

class StockSpanner {
public:
    vector<int> mem;
    vector<int> len;
    StockSpanner() {
        mem.clear();
        len.clear();
    }
    
    int next(int price) {
        mem.push_back(price);
        int l = 1, n = mem.size();
        for(int i = n-2; i >= 0;) {
            if(mem[i]<price) {
                l += len[i];
                i -= len[i];
            } else if(mem[i]==price) {
                l += len[i];
                break;
            } else break;
        }
        len.push_back(l);
        return l;
    }
};

int main() {
    int xlist[] = {100, 80, 60, 70, 60, 75, 85};
    vector<int> x(xlist, xlist+7);
    StockSpanner s = *new StockSpanner();
    for(int i = 0; i < x.size(); i++) {
        printf("%d %d\n", x[i], s.next(x[i]));
    }
    return 0;
}