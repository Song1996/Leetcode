#include <iostream>
#include <algorithm>
using namespace std;

#define Max_String_Length 2048
#define String_Hash_Seed 100000007
typedef unsigned long long ull;

class string_Range_Hash {
    public:
        void cal_Hash(string s){
            int length_s = s.length();
            Hash[0] = s[0];
            for (int i = 1; i < length_s; i++) {
                Hash[i] = Hash[i-1] * B + s[i];
            }
            B_power[0] = 1;
            for (int i = 1; i < length_s; i++) {
                B_power[i] = B_power[i-1] * B;
            }
            return ;
        }

        string_Range_Hash(ull seed, string s){
            B = seed;
            cal_Hash(s);
        }

        ull range_Hash_Query(int a, int b){
            int length_range = b - a;
            if (length_range < 0) {
                printf("error\n");
                return (ull) -1;
            }
            if (a == 0) {
                return Hash[b-1];
            }
            return Hash[b-1] - Hash[a-1]*B_power[length_range];
        }

    private:
        ull B;
        ull Hash[Max_String_Length];
        ull B_power[Max_String_Length];
};

class Solution {
public:
    string longestPalindrome(string s) {
        string reverse_s = s;
        reverse(reverse_s.begin(),reverse_s.end());
        cout<<reverse_s<<endl<<s<<endl;
        string_Range_Hash sRH1 = string_Range_Hash(String_Hash_Seed,s);
        string_Range_Hash sRH2 = string_Range_Hash(String_Hash_Seed,reverse_s);
        for (int l = s.length(); l > 1; l--) {
            for (int i = 0; i + l <= s.length(); i ++) {
                if (l%2==1 && sRH1.range_Hash_Query(i,i+l) == sRH2.range_Hash_Query(s.length()-(i+l-1)-1, s.length()-i) ) {
                    return s.substr(i,l);
                }else if (l%2 == 0 && sRH1.range_Hash_Query(i,i+l) == sRH2.range_Hash_Query(s.length()-(i+l-1)-1, s.length()-i) ) {
                    return s.substr(i,l);
                }
            }
        }
        return s.substr(0,1);
    }
};

int main() {
    string input = "babad";
    Solution s;
    cout<<s.longestPalindrome(input)<<endl;
    input = "babbad";
    cout<<s.longestPalindrome(input)<<endl;
    input = "babb";
    cout<<s.longestPalindrome(input)<<endl;
    return 0;
}