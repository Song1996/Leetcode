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
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int m = matrix.size();
        if(m<1) return false;
        int n = matrix[0].size();
        if(n<1) return false;
        for(int i = 1; i < m; i++){
            if(matrix[i].size()!=n)
                return false;
        }
        if(target<matrix[0][0]||target>matrix[m-1][n-1]) return false;
        int row = -1; int col = -1;
        if(target>matrix[m-1][0]) row = m-1;
        else {
            int l = 0; int r = m-1; int mid;
            while((r-1)>l){
                mid = l + (r-l)/2;
                cout<<target<<' '<<mid<<endl;
                if(target>matrix[mid][0]) l = mid;
                else if(target==matrix[mid][0]) return true;
                else r = mid;
            }
            //cout<<l<<' '<<r<<endl;
            if(matrix[l][0]<=target) row = l;
            if(matrix[r][0]<=target) row = r;
        }
        cout<<row<<endl;
        int l = 0; int r = n-1; int mid;
        while((r-1)>l) {
            mid = l + (r-l)/2;
            if(target>matrix[row][mid]) l = mid;
            else if(target==matrix[row][mid]) return true;
            else r = mid;
        }
        if(matrix[row][l]==target) return true;
        if(matrix[row][r]==target) return true;
        return false;
    }
};

int main () {
    vector<vector<int> > x;
    vector<int> t;
    t.clear(); t.push_back(1); //t.push_back(3); t.push_back(5); t.push_back(7);
    x.push_back(t);
    t.clear(); t.push_back(3); //t.push_back(11); t.push_back(16); t.push_back(20);
    x.push_back(t);
    /*t.clear(); t.push_back(23); t.push_back(30); t.push_back(34); t.push_back(50);
    x.push_back(t);*/
    int target = 3;
    Solution s;
    printf("%s\n",s.searchMatrix(x,target)?"true":"false");
	return 0;
}