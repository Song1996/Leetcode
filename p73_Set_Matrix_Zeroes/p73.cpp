#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <string>
#include <assert.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) {
        int m = matrix.size();
        if(m<1) return;
        int n = matrix[0].size();
        if(n<1) return;
        for(int i = 0; i < m; i++) 
            if(matrix[i].size()!=n) return;
        bool flag_row = false;
        bool flag_col = false;
        for(int i = 0; i<n; i++)
            if(matrix[0][i]==0) flag_row = true;
        for(int i = 0; i<m; i++)
            if(matrix[i][0]==0) flag_col = true;
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][j]==0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < m; i++){
            if(matrix[i][0]==0){
                for(int j = 1; j < n; j++)
                    matrix[i][j] = 0;
            }
        }
        for(int i = 1; i < n; i++){
            if(matrix[0][i]==0){
                for(int j = 1; j < m; j++)
                    matrix[j][i] = 0;
            }
        }
        if(flag_row) for(int i=0; i<n; i++) matrix[0][i] = 0;
        if(flag_col) for(int i=0; i<m; i++) matrix[i][0] = 0;
    }
};

int main () {
    vector<vector<int> > x;
    vector<int> t;
    t.push_back(1);t.push_back(1);t.push_back(2);t.push_back(0);
    x.push_back(t);t.clear();
    /*t.push_back(3);t.push_back(4);t.push_back(5);t.push_back(2);
    x.push_back(t);t.clear();
    t.push_back(1);t.push_back(3);t.push_back(1);t.push_back(5);
    x.push_back(t);t.clear();*/
    for(int i = 0; i<x.size(); i++){
        for(int j = 0; j<x[i].size(); j++){
            printf("%d ",x[i][j]);
        }printf("\n");
    }
    printf("\n");
    Solution s;
    s.setZeroes(x);
    for(int i = 0; i<x.size(); i++){
        for(int j = 0; j<x[i].size(); j++){
            printf("%d ",x[i][j]);
        }printf("\n");
    }
	return 0;
}