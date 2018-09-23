#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <cassert>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
using namespace std;

class TopVotedCandidate {
public:
    int N;
    vector<int> T;
    vector<int> P;
    TopVotedCandidate(vector<int> persons, vector<int> times) {
        N = times.size();
        int n = 0, m = -1;
        vector<int> mem(persons.size(),0);
        for(int i = 0; i < persons.size(); i++) {
            if(++mem[persons[i]]>=n) {
                n = mem[persons[i]];
                m = persons[i];
            } else persons[i] = m;
        }
        T = times;
        P = persons;
    }
    
    int q(int t) {
        int l = 0, r = N - 1, mid;
        while(l < r - 1) {
            mid = l + (r - l)/2;
            if(T[mid]<t) l = mid;
            else r = mid;
        }
        if(T[r]<=t) return P[r];
        if(T[l]<=t) return P[l];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */

int main() {
    return 0;
}