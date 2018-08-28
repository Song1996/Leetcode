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
    void solveSudoku(vector<vector<char> >& board) {
        solve(board, 0, 0);
    }
    bool check(vector<vector<char> >& board, int x, int y) {
        for(int i = 0; i < board.size(); i++) 
            if(i!=x && board[i][y] == board[x][y]) return false;
        for(int i = 0; i < board[x].size(); i++)
            if(i!=y && board[x][i] == board[x][y]) return false;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if((i+3*(x/3))==x && (j+3*(y/3))==y) continue;
                if(board[i+3*(x/3)][j+3*(y/3)]==board[x][y]) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char> >& board, int i, int j) {
        //printf("%d %d\n",i,j);
        if(j==board.size()) return(solve(board, i+1, 0));
        if(i==board.size()) return true;
        if(board[i][j]!='.') return(solve(board, i, j+1));
        for(char c = '1'; c <= '9'; c++) {
            board[i][j] = c;
            if( check(board, i, j) && solve(board, i, j+1) ) return true;
        }
        board[i][j] = '.';
        return false;
    }
};

int main () {
    vector<vector<char> > board(9);
    char t1[]="53..7...."; char t2[]="6..195..."; char t3[]=".98....6.";
    char t4[]="8...6...3"; char t5[]="4..8.3..1"; char t6[]="7...2...6";
    char t7[]=".6....28."; char t8[]="...419..5"; char t9[]="....8..79";
    vector<char> v1(t1,t1+9); board[0] = v1;
    vector<char> v2(t2,t2+9); board[1] = v2;
    vector<char> v3(t3,t3+9); board[2] = v3;
    vector<char> v4(t4,t4+9); board[3] = v4;
    vector<char> v5(t5,t5+9); board[4] = v5;
    vector<char> v6(t6,t6+9); board[5] = v6;
    vector<char> v7(t7,t7+9); board[6] = v7;
    vector<char> v8(t8,t8+9); board[7] = v8;
    vector<char> v9(t9,t9+9); board[8] = v9;
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[i].size(); j++) {
            printf("%c ",board[i][j]);
        }printf(";\n");
    }
    Solution s;
    s.solveSudoku(board);
    printf("\n\n");
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[i].size(); j++) {
            printf("%c ",board[i][j]);
        }printf(";\n");
    } 
	return 0;
}