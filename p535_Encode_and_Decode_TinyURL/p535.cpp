#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        auto it = forward_map.find(longUrl);
        if( it != forward_map.end() ) return it->second;
        else {
            string rs = random_string();
            while(reverse_map.find(rs) != reverse_map.end() ) {
                rs = random_string();
            }
            forward_map[longUrl] = rs;
            reverse_map[rs] = longUrl;
            return rs;
        }
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        auto it = reverse_map.find(shortUrl);
        if( it == reverse_map.end() ) return string();
        else return it->second;
    }
private:
    static const int tinyUrlLength = 32;
    unordered_map<string, string> forward_map;
    unordered_map<string, string> reverse_map;
    
    string random_string() {
        string ret;
        for(int i = 0; i < tinyUrlLength; i++) {
            ret.push_back(random_char());
        }
        return ret;
    }
    
    char random_char() {
        int n = rand() % 62;
        if(n<10) return '0' + n;
        else if(n < 10 +26) return 'a' + n;
        else return 'A' + n;
    }
};