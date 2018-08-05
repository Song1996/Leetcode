#include <iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows==1) return s;
        int base = 2*numRows - 2;
        string result = s;
        int n = 0;
        for(int i = 0; i < s.length(); i += base)
            result[n++] = s[i];
        for(int i = 1; i < numRows-1; i++){
            //cout<<i<<endl;
            int j = 0;
            while (j*base+i < s.length()){
                result[n++] = s[j*base+i];
                if ((j+1)*base-i < s.length()) result[n++] = s[(j+1)*base-i];
                j++;
            }
        }
        for(int i = numRows-1; i < s.length(); i += base)
            result[n++] = s[i];
        return result;
    }
};

int main() {
    Solution s;
    string input;
    int numRows;
    input = "PAYPALISHIRING", numRows = 3;
    cout<<s.convert(input,numRows)<<endl<<"PAHNAPLSIIGYIR"<<endl;
    input = "PAYPALISHIRING", numRows = 4;
    cout<<s.convert(input,numRows)<<endl<<"PINALSIGYAHRPI"<<endl;
}