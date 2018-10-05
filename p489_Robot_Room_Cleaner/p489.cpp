#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
#include <cassert>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
using namespace std;

class Robot {
  public:
    // Returns true if the cell in front is open and robot moves into the cell.
    // Returns false if the cell in front is blocked and robot stays in the current cell.
    bool move();
    // Robot will stay in the same cell after calling turnLeft/turnRight.
    // Each turn will be 90 degrees.
    void turnLeft();
    void turnRight();
    // Clean the current cell.
    void clean();
};
class Solution {
public:
    int make_key(int x, int y) {
        return (x<<16)|(y&0x0000ffff);
    }
    void helper(int x, int y, unordered_set<int>& mem, Robot& r, int dir) {
        if(mem.find(make_key(x,y))==mem.end()){
            //printf("%d %d\n",x,y);
            r.clean();
            mem.insert(make_key(x,y));
            for(int i = 0; i < dir; i++) r.turnRight();
            if(r.move()) helper(x,y+1,mem,r,0);
            r.turnLeft(); if(r.move()) helper(x+1,y,mem,r,1);
            r.turnLeft(); if(r.move()) helper(x,y-1,mem,r,2);
            r.turnLeft(); if(r.move()) helper(x-1,y,mem,r,3);
            r.turnLeft();
            for(int i = 0; i < dir; i++) r.turnLeft();
        }
        r.turnLeft(); r.turnLeft(); 
        r.move();
        r.turnLeft(); r.turnLeft();
        return;
    }
    void cleanRoom(Robot& robot) {
        unordered_set<int> mem;
        mem.clear();
        helper(0, 0, mem, robot, 0);
    }
};

int main() {
    return 0;
}