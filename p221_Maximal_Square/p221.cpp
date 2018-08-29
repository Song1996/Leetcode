#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <assert.h>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        if(matrix.size()==0) return 0;
        if(matrix[0].size()==0) return 0;
        vector<vector<int> > memx(matrix.size());
        for(int i = 0; i < memx.size(); i++) memx[i].resize(matrix[i].size(),0);
        vector<vector<int> > memy(matrix.size());
        for(int i = 0; i < memy.size(); i++) memy[i].resize(matrix[i].size(),0);
        vector<vector<int> > mems(matrix.size());
        for(int i = 0; i < mems.size(); i++) mems[i].resize(matrix[i].size(),0);
        if(matrix[0][0]=='1') {memx[0][0]=1; memy[0][0]=1; mems[0][0]=1;}
        for(int i = 1; i < matrix.size(); i++) 
            if(matrix[i][0]=='1') {memx[i][0]=memx[i-1][0]+1; memy[i][0]=1; mems[i][0]=1;}
            else {memx[i][0]=0; memy[i][0]=0; mems[i][0]=0;}
        for(int i = 1; i < matrix[0].size(); i++) 
            if(matrix[0][i]=='1') {memy[0][i]=memy[0][i-1]+1; memx[0][i]=1; mems[0][i]=1;}
            else {memx[0][i]=0; memy[0][i]=0; mems[0][i]=0;}
        for(int i = 1; i < matrix.size(); i++) {
            for(int j = 1; j < matrix[i].size(); j++) {
                if(matrix[i][j]=='0') {memx[i][j]=0; memy[i][j]=0; mems[i][j]=0;}
                else {
                    memx[i][j] = memx[i-1][j]+1;
                    memy[i][j] = memy[i][j-1]+1;
                    mems[i][j] = min(memx[i][j],mems[i-1][j-1]+1);
                    mems[i][j] = min(mems[i][j],memy[i][j]);
                }
            }
        }
        int ans = -1;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                ans = max(ans, mems[i][j]);
            }
        }
        return ans*ans;
    }
};

int main () {
    //char x1[] = "10100"; char x2[] = "10111";
    //char x3[] = "11111"; char x4[] = "10010";
    char x1[] = "11"; char x2[] = "11";
    //char x3[] = "11"; char x4[] = "11";
    //vector<char> v1(x1,x1+5); vector<char> v2(x2,x2+5);
    //vector<char> v3(x3,x3+5); vector<char> v4(x4,x4+5);
    vector<char> v1(x1,x1+2); vector<char> v2(x2,x2+2);
    //vector<char> v3(x3,x3+2); vector<char> v4(x4,x4+2);
    vector<vector<char> > matrix(2);
    matrix[0] = v1; matrix[1] = v2; //matrix[2] = v3; matrix[3] = v4;
    Solution s;
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[i].size(); j++) {
            printf("%c",matrix[i][j]);
        }printf("\n");
    }
    printf("%d\n",s.maximalSquare(matrix));
	return 0;
}