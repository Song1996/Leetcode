#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <cassert>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        string x = " ";
        vector<string> ans;
        int last = 0, leftlength = maxWidth;
        for(int i = 0; i < words.size(); i++) {
            if( leftlength >= int(words[i].length())) {
                leftlength -= (words[i].length() + 1);
                continue;
            } else {
                leftlength += i - last;
                int temp_num_words = i - last;
                if(temp_num_words==1) {
                    string temp_s = words[last];
                    temp_s += string(maxWidth - words[last].length(),' ');
                    ans.push_back(temp_s);
                    leftlength = maxWidth - (words[i].length()+1);
                    last = i;
                    continue;
                }
                int base_num_spaces = leftlength / (temp_num_words - 1);
                int num_extra_space_words = leftlength - base_num_spaces * (temp_num_words - 1);
                string temp_s = "";
                string tstring(base_num_spaces,' '); 
                for(int j = 0; j < num_extra_space_words; j++) temp_s += (words[j+last]+tstring+" ");
                for(int j = num_extra_space_words + last; j < i - 1; j++) temp_s += (words[j]+tstring);
                temp_s += words[i-1];
                ans.push_back(temp_s);
                last = i;
                leftlength = maxWidth - (words[i].length()+1);
            }
        }
        int temp_num_words = words.size() - last;
        string temp_s = "";
        for(int i = last; i < words.size() - 1; i++) temp_s += words[i] + " ";
        temp_s += words[words.size()-1];
        temp_s += string(maxWidth - temp_s.length(),' ');
        ans.push_back(temp_s);
        return ans;
    }
};

int main() {
    int maxwidth;
    vector<string> y;
    Solution s;
    string x1[] = {"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> v1(x1,x1+sizeof(x1)/sizeof(string));
    maxwidth = 16;
    y = s.fullJustify(v1,maxwidth); for(int i = 0; i < y.size(); i++) printf("%s;\n",y[i].c_str()); printf("\n");
    string x2[] = {"What","must","be","acknowledgment","shall","be"};
    vector<string> v2(x2,x2+sizeof(x2)/sizeof(string));
    maxwidth = 16;
    y = s.fullJustify(v2,maxwidth); for(int i = 0; i < y.size(); i++) printf("%s;\n",y[i].c_str()); printf("\n");
    string x3[] = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    vector<string> v3(x3, x3+sizeof(x3)/sizeof(string));
    maxwidth = 20;
    y = s.fullJustify(v3,maxwidth); for(int i = 0; i < y.size(); i++) printf("%s;\n",y[i].c_str()); printf("\n");
    string x4[] = {"Listen","to","many,","speak","to","a","few."};
    vector<string> v4(x4,x4+sizeof(x4)/sizeof(string));
    maxwidth = 6;
    y = s.fullJustify(v4,maxwidth); for(int i = 0; i < y.size(); i++) printf("%s;\n",y[i].c_str()); printf("\n");
    return 0;
}