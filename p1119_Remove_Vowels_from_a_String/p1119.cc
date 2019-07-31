#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    string removeVowels(string S) {
        unordered_set<char> mem;
        mem.insert('a');
        mem.insert('e');
        mem.insert('i');
        mem.insert('o');
        mem.insert('u');
        string ans;
        for(char c: S) {
            if(mem.find(c) == mem.end()) {
                ans.push_back(c);
            }
        }
        return ans;
    }
};