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

class NumMatrix {
public:
    vector<vector<int> > M;
    NumMatrix(vector<vector<int> > matrix) {
        M = matrix;
        for(int i = 1; M.size()>0 && i < M[0].size(); i++) M[0][i] += M[0][i-1];
        for(int i = 1; i < M.size(); i++) {
            for(int j = 0; j < M[i].size(); j++) {
                if(j==0) M[i][j] += M[i-1][j];
                else M[i][j] += (M[i-1][j]+M[i][j-1]-M[i-1][j-1]);
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int s1 = M[row2][col2];
        int s2 = col1>0?M[row2][col1-1]:0;
        int s3 = row1>0?M[row1-1][col2]:0;
        int s4 = (col1>0&&row1>0)?M[row1-1][col1-1]:0;
        return s1+s4-s2-s3;
    }
};

int main() {
    int x1[] = {3, 0, 1, 4, 2}; vector<int> v1(x1, x1+5);
    int x2[] = {5, 6, 3, 2, 1}; vector<int> v2(x2, x2+5);
    int x3[] = {1, 2, 0, 1, 5}; vector<int> v3(x3, x3+5);
    int x4[] = {4, 1, 0, 1, 7}; vector<int> v4(x4, x4+5);
    int x5[] = {1, 0, 3, 0, 5}; vector<int> v5(x5, x5+5);
    vector<vector<int> > M(5); 
    M[0] = v1; M[1] = v2; M[2] = v3; M[3] = v4; M[4] = v5;
    NumMatrix s(M);
    printf("%d\n",s.sumRegion(2, 1, 4, 3));
    printf("%d\n",s.sumRegion(1, 1, 2, 2));
    printf("%d\n",s.sumRegion(1, 2, 2, 4));
    return 0;
}