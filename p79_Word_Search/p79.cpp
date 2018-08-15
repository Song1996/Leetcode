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
    bool exist(vector<vector<char> >& board, string word) {
        int m = board.size();
        if(m<1&&word.length()>=1) return false;
        if(m<1&&word.length()<1)  return true;
        int n = board[0].size();
        for(int i = 0; i<m; i++) {
            if(board[i].size()!=n) assert(0);
        }
        if(n<1&&word.length()>=1) return false;
        if(n<1&&word.length()<1)  return true;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(dfs(board, word, 0, i, j, m, n)) return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char> >& board, string& word, int p, int x, int y, int m, int n) {
        if(p==word.size()) return true;
        if(x<0||x>=m) return false;
        if(y<0||y>=n) return false;
        if(board[x][y]!=word[p]) return false;
        board[x][y] = char(-1);
        if(dfs(board,word,p+1,x+1,y,m,n)) {
            board[x][y] = word[p];
            return true;
        }
        if(dfs(board,word,p+1,x,y+1,m,n)) {
            board[x][y] = word[p];
            return true;
        }
        if(dfs(board,word,p+1,x-1,y,m,n)) {
            board[x][y] = word[p];
            return true;
        }
        if(dfs(board,word,p+1,x,y-1,m,n)) {
            board[x][y] = word[p];
            return true;
        }
        board[x][y] = word[p];
        return false;
    }
};

int main () {
    vector<vector<char> > x;
    vector<char> t; 
    t.push_back('A'); t.push_back('B'); t.push_back('C'); t.push_back('E');
    x.push_back(t); t.clear();
    t.push_back('S'); t.push_back('F'); t.push_back('C'); t.push_back('S');
    x.push_back(t); t.clear();
    t.push_back('A'); t.push_back('D'); t.push_back('E'); t.push_back('E');
    x.push_back(t);
    Solution s;
    printf("%s\n",s.exist(x,"ABCCED")?"true":"false");
    printf("%s\n",s.exist(x,"SEE")?"true":"false");
    printf("%s\n",s.exist(x,"ABCB")?"true":"false");
	return 0;
}