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
#include <cmath>
using namespace std;

class Permutation {
    public:
    bool next_permutation(vector<int>& A) {
        int k = -1;
        for(int i = 0; i < A.size()-1; i++) if(A[i]<A[i+1]) k = i;
        if(k==-1) return false;
        int l = k+1;
        for(int i = k+2; i < A.size(); i++) if(A[i]>A[k]) l = i;
        swap(A[k],A[l]);
        reverse(A.begin()+k+1, A.begin()+A.size());
        return true;
    }
};

int main() {
    int x[] = {5,4,7,5,3,2};
    vector<int> v(x,x+6);
    Permutation p;
    while(p.next_permutation(v)) {
        for(int i = 0; i < v.size(); i++) printf("%d ",v[i]); printf("\n");
    }
    return 0;
}