#include<string>
using namespace std;

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        if(abbr.empty() && word.empty()) return true;
        if(abbr.empty() != word.empty()) return false;
        if(abbr[0] <= 'z' && abbr[0] >= 'a') {
            int p = 0;
            while(p < word.length() && p < abbr.length() && abbr[p] <= 'z' && abbr[p] >= 'a') {
                if(word[p] != abbr[p]) return false;
                p++;
            }
            if(p == abbr.length() && p < word.length()) return false;
            if(p == word.length() && p < abbr.length()) return false;
            return validWordAbbreviation( word.substr(p), abbr.substr(p) );
        } else if(abbr[0] <= '9' && abbr[0] >= '1') {
            int p = 0, n = 0;
            while( p < abbr.length() && abbr[p] <= '9' && abbr[p] >= '0') {
                n *= 10;
                n += abbr[p] - '0';
                p++;
            }
            if(n > word.length()) return false;
            else return validWordAbbreviation(word.substr(n), abbr.substr(p) );
        } else {
            return false;
        }
    }
};