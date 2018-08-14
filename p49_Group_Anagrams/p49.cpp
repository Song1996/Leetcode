#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <string>
#include <assert.h>
#include <algorithm>
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
            return;
        }

        string_Range_Hash(ull seed, string s, bool fast){
            B = seed;
            if(!fast) cal_Hash(s);
        }
        
        ull range_Hash_Query(int a, int b){
            int length_range = b - a;
            if (length_range < 0) {
                printf("error\n");
                return (ull) -1;
            }
            if (a == 0) return Hash[b-1];
            return Hash[b-1] - Hash[a-1]*B_power[length_range];
        }
    private:
        ull B;
        ull Hash[Max_String_Length];
        ull B_power[Max_String_Length];
};

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        vector<vector<string> > ans;
        map<ull, vector<string> > d;
        for(vector<string>::iterator it = strs.begin(); it!=strs.end(); it++) {
            string temp = *it;
            sort(temp.begin(),temp.end());
            string_Range_Hash sRH = string_Range_Hash(String_Hash_Seed, temp, true);
            ull h = sRH.fast_cal_Hash(temp);
            
            if(d.find(h)==d.end()){
                vector<string> t;
                t.push_back(*it);
                d[h] = t;
            }else {
                d[h].push_back(*it);
            }
        }
        for(map<ull, vector<string> >::iterator it = d.begin(); it!=d.end(); it++){
            ans.push_back(it->second);
        }
        /*
        for(vector<string>::iterator it = strs.begin(); it!= strs.end(); it++){
            t.clear();
            sort(it->begin(),it->end());
            t.push_back(*it);
            ans.push_back(t);
        }*/
        return ans;
    }
};

int main () {
    vector<string> x;
    string xlist[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    for(int i = 0; i < 6; i++) {
        x.push_back(xlist[i]);
    }
    x.push_back("");
    Solution s;
    vector<vector<string> > y = s.groupAnagrams(x);
    for(vector<vector<string> >::iterator it = y.begin(); it!=y.end(); it++){
        for(vector<string>:: iterator itt = it->begin(); itt!=it->end(); itt++){
            printf("%s, ",itt->c_str());
        }printf("\n");
    }
	return 0;
}

