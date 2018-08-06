#include <iostream>
#include <vector>
using namespace std;

#define Max_Deepth 256

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        /*
        string yList[] = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
        vector<string> y;
        for (int i = 0; i < 9; i++) {
            y.push_back(yList[i]);
        }*/
        result.clear();
        total_deepth = digits.length();
        if (total_deepth == 0) {
            return result;
        }
        cdigits = digits;
        dfs(0);
        return result;
    }
private:
    vector<string> result;
    string cdigits;
    char buff[Max_Deepth];
    int total_deepth;
    char** map;
    void dfs (int deepth) {
        int n = int(cdigits[deepth]) - int('2');
        if (n < 5) {
            for (int i = 0; i < 3; i ++) {
                buff[deepth] = char(n*3 + i + int('a'));
                if (deepth == total_deepth-1) {
                    string one_result(buff, total_deepth);
                    result.push_back(one_result);
                }else {
                    dfs(deepth + 1);
                }
            }
        }else if (n==5){
            for (int i = 0; i < 4; i ++) {
                buff[deepth] = char(i + int('p'));
                if (deepth == total_deepth-1) {
                    string one_result(buff, total_deepth);
                    result.push_back(one_result);
                }else {
                    dfs(deepth + 1);
                }
            }
        }else if (n==6){
            for (int i = 0; i < 3; i ++) {
                buff[deepth] = char(i + int('t'));
                if (deepth == total_deepth-1) {
                    string one_result(buff, total_deepth);
                    result.push_back(one_result);
                }else {
                    dfs(deepth + 1);
                }
            }
        }else if (n==7){
            for (int i = 0; i < 4; i ++) {
                buff[deepth] = char( i + int('w'));
                if (deepth == total_deepth-1) {
                    string one_result(buff, total_deepth);
                    result.push_back(one_result);
                }else {
                    dfs(deepth + 1);
                }
            }
        }
    }
};

int main () {
    Solution s;
    string x = "7";
    string yList[] = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    vector<string> y;
    for (int i = 0; i < 9; i++) {
        y.push_back(yList[i]);
    }
    printf("%s\n",x.c_str());
    for (vector<string>:: iterator it = y.begin(); it != y.end(); it ++) {
        printf("%s ",(*it).c_str());
    }printf("\n");
    vector<string> z = s.letterCombinations(x);
    for (vector<string>:: iterator it = z.begin(); it != z.end(); it ++) {
        printf("%s ",(*it).c_str());
    }printf("\n");
}
