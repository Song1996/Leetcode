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
    void rotate(vector<vector<int> >& matrix) {
        int n = matrix.size();
        for(vector<vector<int> >::iterator it = matrix.begin(); it!=matrix.end(); it++){
            if(it->size()!=n) assert(0);
        }
        if(n%2==1) {
            for(int i = n/2; i>=1 ; i--) {
                for(int j = n/2; j>=1; j--) {
                    swap(matrix[(n/2)-j][(n/2)-i], matrix[(n/2)-i][(n/2)+j]);
                    swap(matrix[(n/2)-j][(n/2)-i], matrix[(n/2)+j][(n/2)+i]);
                    swap(matrix[(n/2)-j][(n/2)-i], matrix[(n/2)+i][(n/2)-j]);
                }
            }
            for(int i = n/2; i >= 1; i--) {
                swap(matrix[(n/2)-i][(n/2)],matrix[(n/2)][(n/2)+i]);
                swap(matrix[(n/2)-i][(n/2)],matrix[(n/2)+i][(n/2)]);
                swap(matrix[(n/2)-i][(n/2)],matrix[(n/2)][(n/2)-i]);
            }
        }else {
            for(int i = 0; i < n/2; i++) {
                for(int j = 0; j < n/2; j++) {
                    swap(matrix[(n/2-1)-i][(n/2-1)-j],matrix[(n/2-1)-j][(n/2)+i]);
                    swap(matrix[(n/2-1)-i][(n/2-1)-j],matrix[(n/2)+i][(n/2)+j]);
                    swap(matrix[(n/2-1)-i][(n/2-1)-j],matrix[(n/2)+j][(n/2-1)-i]);
                }
            }

        }
    }
};

int main () {
    vector<vector<int> >x;
    vector<int> t;
    for(int i = 0; i < 4; i++) {
        t.clear();
        for(int j = 0; j < 4; j++) {
            t.push_back(i*4+j+1);
        }
        x.push_back(t);
    }
    Solution s;
    s.rotate(x);
    for(vector<vector<int> >::iterator it = x.begin(); it!=x.end(); it++){
        for(vector<int>::iterator itt=it->begin(); itt != it->end(); itt++) {
            printf("%2d ",*itt);
        }printf("\n");
    }
	return 0;
}
