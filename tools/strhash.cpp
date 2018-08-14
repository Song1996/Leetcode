#include <iostream>
using namespace std;

#define Max_String_Length 2048
#define String_Hash_Seed 100000007
typedef unsigned long long ull;

class string_Range_Hash {
    public:
        ull fast_cal_Hash(string s){
            int length_s = s.length();
            if(length_s==0) return 0;
            ull fast_hash = s[0];
            for (int i = 1; i < length_s; i++) {
                fast_hash = fast_hash * B + s[i];
            }
            return fast_hash;
        }

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

        string_Range_Hash(ull seed, string s, bool fast){
            B = seed;
            if (!fast) cal_Hash(s);
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

int main(){
    string s = "hello_world\nhello_world\n";
    printf("%s",s.c_str());
    printf("%s\n",s.substr(0,11).c_str());
    printf("%s\n",s.substr(12,11).c_str());
    string_Range_Hash sRH = string_Range_Hash(String_Hash_Seed,s,false);
    //sRH.cal_Hash(s);
    ull h1 = sRH.range_Hash_Query(0,12);
    ull h2 = sRH.range_Hash_Query(12,24);
    cout<<h1<<' '<<h2<<endl;
    h1 = sRH.range_Hash_Query(0,6);
    h2 = sRH.range_Hash_Query(12,18);
    cout<<h1<<' '<<h2<<endl;
    h1 = sRH.range_Hash_Query(0,7);
    h2 = sRH.range_Hash_Query(12,20);
    cout<<h1<<' '<<h2<<endl;
    string s1 = "hello\n";
    string_Range_Hash sRH_ = string_Range_Hash(String_Hash_Seed,s1,true);
    h1 = sRH_.fast_cal_Hash(s1);
    string s2 = "hello\n";
    string_Range_Hash sRH__ = string_Range_Hash(String_Hash_Seed,s2,true);
    h2 = sRH__.fast_cal_Hash(s2);
    cout<<h1<<' '<<h2<<endl;
    return 0;
}
