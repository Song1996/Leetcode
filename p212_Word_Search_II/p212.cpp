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
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        vector<string> ans;
        map<string, bool> d;
        for(int i = 0; i < words.size(); i++) {
            if(d.find(words[i])!=d.end()) continue;
            d[words[i]] = exist(board,words[i]);
            if(d[words[i]]) ans.push_back(words[i]);
        }
        return ans;
    }

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
    t.push_back('o'); t.push_back('a'); t.push_back('a'); t.push_back('n');
    x.push_back(t); t.clear();
    t.push_back('e'); t.push_back('t'); t.push_back('a'); t.push_back('e');
    x.push_back(t); t.clear();
    t.push_back('i'); t.push_back('h'); t.push_back('k'); t.push_back('r');
    x.push_back(t); t.clear();
    t.push_back('i'); t.push_back('f'); t.push_back('l'); t.push_back('v');
    x.push_back(t);
    Solution s;
    vector<string> ss;
    ss.push_back(string("oath"));
    ss.push_back(string("pea"));
    ss.push_back(string("eat"));
    ss.push_back(string("rain"));
    vector<string> y = s.findWords(x,ss);
    for(int i = 0; i < y.size(); i++) {
        printf("%s\n",y[i].c_str());
    }
    /*printf("%s\n",s.exist(x,"oath")?"true":"false");
    printf("%s\n",s.exist(x,"pea")?"true":"false");
    printf("%s\n",s.exist(x,"eat")?"true":"false");
    printf("%s\n",s.exist(x,"rain")?"true":"false");*/
	return 0;
}