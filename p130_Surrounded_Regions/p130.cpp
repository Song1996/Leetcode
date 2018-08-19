#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <assert.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char> >& board) {
        bool touch_flag = false;
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if((i==0||j==0||i==board.size()-1||j==board[i].size()-1) && board[i][j]=='O')
                    dfs(board, i, j);
            }
        }
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(board[i][j]=='-') board[i][j] = 'O';
                else if(board[i][j]=='O') board[i][j] = 'X';
            }
        }
    }
    void dfs(vector<vector<char> >& board, int x, int y) {
        board[x][y] = '-';
        if(x+1<board.size() && board[x+1][y]=='O') dfs(board, x+1, y);
        if(x-1>=0 && board[x-1][y]=='O') dfs(board, x-1, y);
        if(y+1<board[x].size() && board[x][y+1]=='O') dfs(board, x, y+1);
        if(y-1>=0 && board[x][y-1]=='O' )dfs(board, x, y-1);
        return;
    }
};

int main () {
    vector<vector<char> > x;
    vector<char> t;
    //for(int i = 0; i<4; i++)t.push_back('X');
    //x.push_back(t); t.clear();
    t.push_back('O'); t.push_back('X'); t.push_back('X'); t.push_back('O'); t.push_back('X');
    x.push_back(t); t.clear();
    t.push_back('X'); t.push_back('O'); t.push_back('O'); t.push_back('X'); t.push_back('O');
    x.push_back(t); t.clear();
    t.push_back('X'); t.push_back('O'); t.push_back('X'); t.push_back('O'); t.push_back('X');
    x.push_back(t); t.clear();
    t.push_back('O'); t.push_back('X'); t.push_back('O'); t.push_back('O'); t.push_back('O');
    x.push_back(t); t.clear();
    t.push_back('X'); t.push_back('X'); t.push_back('O'); t.push_back('X'); t.push_back('O');
    x.push_back(t); t.clear();
    for(int i = 0; i < x.size(); i++) {
        for(int j = 0; j < x[i].size(); j++) {
            printf("%c ",x[i][j]);
        }printf("\n");
    }printf("\n");
    Solution s;
    s.solve(x);
    for(int i = 0; i < x.size(); i++) {
        for(int j = 0; j < x[i].size(); j++) {
            printf("%c ",x[i][j]);
        }printf("\n");
    }
	return 0;
}