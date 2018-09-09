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

class RLEIterator {
public:
    vector<int> c;
    vector<int> n;
    int p;
    RLEIterator(vector<int> A) {
        c.clear(); c.resize(A.size()/2);
        n.clear(); n.resize(A.size()/2);
        for(int i = 0; i < A.size()/2; i++) {
            n[i] = A[2*i+1]; c[i] = A[2*i];
        }
        p = 0;
    }
    
    int next(int x) {
        if(p==c.size()) return -1;
        if(c[p]>x){
            c[p] -= x; return n[p];
        } else if(c[p]==x) {
            c[p] -= x;
            return n[p];
            /*while(c[p]==0 && p<c.size()) p++;
            if(p==c.size()) return -1;
            else return n[p-1];*/
        } else {
            while(x>c[p] && p<c.size()) {
                x -= c[p]; p++;
            }
            if(p==c.size()) return -1;
            if(x<=0) {
                c[p] = -1*x;
                return n[p];
            } else {
                c[p] -= x;
                return n[p];
            }
        }
    }
};

int main() {
    int xlist[] = {3,8,0,9,2,5};
    vector<int> x(xlist, xlist+6);
    RLEIterator s = *new RLEIterator(x);
    int qlist[] = {2,1,1,2};
    vector<int> q(qlist, qlist+4);
    for(int i = 0; i < q.size(); i++) printf("%d %d\n",q[i],s.next(q[i]));
    return 0;
}