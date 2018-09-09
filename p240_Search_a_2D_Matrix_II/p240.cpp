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
    vector<vector<int> > m;
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        if(matrix.size()==0) return false;
        if(matrix[0].size()==0) return false;
        int i = 0, j = matrix[0].size()-1;
        while(i<matrix.size() && i>=0 && j<=matrix[i].size() && j>=0) {
            if(matrix[i][j]>target) j--;
            else if(matrix[i][j]<target) i++;
            else return true;
        }
        return false;
    }
};
int main() {
    int x1[] = {1,   4,  7, 11, 15}; vector<int> v1(x1, x1+5);
    int x2[] = {2,   5,  8, 12, 19}; vector<int> v2(x2, x2+5);
    int x3[] = {3,   6,  9, 16, 22}; vector<int> v3(x3, x3+5);
    int x4[] = {10, 13, 14, 17, 24}; vector<int> v4(x4, x4+5);
    int x5[] = {18, 21, 23, 26, 30}; vector<int> v5(x5, x5+5);
    vector<int> m[] = {v1, v2, v3, v4, v5};
    vector<vector<int> > matrix(m, m+5);
    Solution s;
    printf("%s\n",s.searchMatrix(matrix, 5)?"true":"false");
    printf("%s\n",s.searchMatrix(matrix, 20)?"true":"false");
    return 0;
}