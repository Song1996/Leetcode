#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector< vector<char> >& board) {
        for(int i = 0; i < 9; i ++){
            hclear();
            for(int j = 0; j < 9; j ++){
                if(!htest(int(board[i][j]-'1'))) return false;
            }
        }

        for(int i = 0; i < 9; i ++){
            hclear();
            for(int j = 0; j < 9; j ++){
                if(!htest(int(board[j][i]-'1'))) return false;
            }
        }

        for(int i = 0; i < 9; i ++) {
            hclear();
            for(int j = 0; j < 9; j ++){
                if(!htest(int(board[(i/3)*3+j/3][(i%3)*3+j%3]-'1'))) return false;
            }
        }
        return true;
    }
private:
    int h[9];
    bool htest(int x) {
        if (x<0 || x>9) return true;
        if (h[x] > 0) return false;
        h[x] = 1;
        return true;
    }
    void hclear() {
        memset(h, 0, sizeof(h));
    }
};
int main () {
    Solution s;
    vector< vector<char> > board;
    printf("%s\n",s.isValidSudoku(board)?"true":"false");
	return 0;
}

