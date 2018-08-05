#include <iostream>
using namespace std;
#define Max_String_Length 40960
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
    int strStr(string haystack, string needle) {
        int noexist = -1;
        if (haystack.length()==0 || needle.length()==0) return noexist;
        if (haystack.length() < needle.length()) return noexist;
        string_Range_Hash sRH1 = string_Range_Hash(String_Hash_Seed, haystack);
        string_Range_Hash sRH2 = string_Range_Hash(String_Hash_Seed, needle);
        ull p = sRH2.range_Hash_Query(0,needle.length());
        for (int i = 0; i + needle.length() <= haystack.length(); i++) {
            if (sRH1.range_Hash_Query(i,i + needle.length()) == p) return i;
        }
        return noexist;
    }
};

int main () {
    string haystack, needle;
    int y;
    Solution s;
    haystack = "hello", needle = "ll", y = 2;
    printf("%d %d\n",y,s.strStr(haystack,needle));
    haystack = "aaaaa", needle = "bba", y = -1;
    printf("%d %d\n",y,s.strStr(haystack,needle));
}