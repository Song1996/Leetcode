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
    int minMutation(string beginWord, string endWord, vector<string>& wordList) {
        //printf("%s\n",beginWord.c_str());
        //printf("%s\n",endWord.c_str());
        //for(int i = 0; i < wordList.size(); i++) printf("%s ",wordList[i].c_str()); printf("\n");
        bool flag = false;
        for(int i = 0; i < wordList.size(); i++) if(endWord==wordList[i]) flag = true;
        map<string, int> dict;
        for(int i = 0; i < wordList.size(); i++) dict[wordList[i]] = 0;
        vector<char> gene; gene.push_back('A'); gene.push_back('C'); 
        gene.push_back('T'); gene.push_back('G');
        if (!flag) return -1;
        map<string,int> vis;
        map<string,int> vis2;
        vis[beginWord] = 0;
        vis2[endWord] = 1;
        queue<string> q1;
        queue<string> q2;
        string s;
        string st;
        char ct;
        q1.push(beginWord);
        q2.push(endWord);
        while(q1.size()>0 && q2.size()>0) {
            s = q1.front(); q1.pop();
            //printf("%s %d\n",s.c_str(),vis[s]);
            st = s;
            for(int i = 0; i < s.length(); i++) {
                for(int j = 0; j < 4; j++) {
                    ct = gene[j];
                    if(ct == s[i]) continue;
                    st[i] = ct;
                        if(dict.find(st)!=dict.end() && vis.find(st)==vis.end()) {
                            vis[st] = vis[s] + 1;
                            if(st==endWord) return vis[st];
                            if(vis2.find(st)!=vis2.end()) return vis[st]+vis2[st]-1;
                            q1.push(st);
                    }
                }
                st[i] = s[i];
            }

            s = q2.front(); q2.pop();
            //printf("%s %d\n",s.c_str(),vis2[s]);
            st = s;
            for(int i = 0; i < s.length(); i++) {
                for(int j = 0; j < 4; j++) {
                    ct = gene[j];
                    if(ct == s[i]) continue;
                    st[i] = ct;
                        if(dict.find(st)!=dict.end() && vis2.find(st)==vis2.end()) {
                            vis2[st] = vis2[s] + 1;
                            if(st==beginWord) return vis2[st];
                            if(vis.find(st)!=vis.end()) return vis[st]+vis2[st]-1;
                            q2.push(st);
                    }
                }
                st[i] = s[i];
            }
        }
        return -1;
    }
};

int main () {
    string xlist[] = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};
    vector<string> x(xlist, xlist+sizeof(xlist)/sizeof(string));
    //for(int i = 0; i < x.size(); i++) printf("%s ",x[i].c_str()); printf("\n");
    Solution s;
    printf("%d\n",s.minMutation("AACCGGTT","AAACGGTA",x));
	return 0;
}